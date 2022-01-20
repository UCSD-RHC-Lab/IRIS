/***************************************
 * Filename: engine.cpp
 * Students: Aayush Naik, Rebecca Kreitinger, Daniel Koohmarey
 * HRI Final Project
 * 
 * Description: This module is responsible for using the command messages
 * to move the robot like a racecar.
 * 
 * How to use: see README.md
 *******************************************/

#include <autobot/engine.h>
#include <cmath>
#include <iostream>


Engine::Engine(): throttle_(0.0), steering_(0.0), vel_(0.0), brake_(false),
                  c_heading_(0.0), c_dist_(0.0) {
  vel_pub_ = nh_.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 10);
  
  command_sub_ = 
    nh_.subscribe<autobot_msgs::Command>("autobot/commands", 10, 
                                         &Engine::commandCallback, this);
  safety_sub_ =
    nh_.subscribe<autobot_msgs::Safety>("autobot/safety", 10,
                                        &Engine::safetyCallback, this);
  
  // Timer to publish velocity every 100 ms
  timer_ = nh_.createTimer(ros::Duration(0.1), &Engine::velocityCallback, this);
}

void Engine::commandCallback(const autobot_msgs::Command::ConstPtr& command) {
  // Sets engine values to match the values received
  brake_ = command->brake;
  if (command->set_throttle)
    throttle_ = command->throttle;
  if (command->set_steering)
    steering_ = command->steering;
}

void Engine::safetyCallback(const autobot_msgs::Safety::ConstPtr& msg) {
  // Sets engine safety values to match the values received
  danger_ = msg->danger;
  c_heading_ = msg->heading;
  c_dist_ = msg->distance;
}

void Engine::velocityCallback(const ros::TimerEvent& event) {
  // Apply acceleration
  vel_ += engine_params::THROTTLE_FACTOR * throttle_;
  // Apply friction decay
  vel_ *= engine_params::FRICTION_DECAY_FACTOR;
  // Apply brake decay
  if (brake_)
    vel_ *= engine_params::BRAKE_DECAY;

  // Clamp velocity
  vel_ = std::max<double>(-engine_params::MAX_VEL, 
                          std::min<double>(engine_params::MAX_VEL, vel_));

  if (fabs(vel_) < engine_params::MIN_THRESH)
    vel_ = 0.0;
  
  geometry_msgs::Twist twist;
  // Check danger and avoid collision
  if (danger_ && c_heading_ < 0) {
    steering_ = -engine_params::SAFETY_STEERING;
  }
  else if (danger_ && c_heading_ > 0) {
    steering_ = engine_params::SAFETY_STEERING;
  } else if (!danger_) {
    if (steering_ == engine_params::SAFETY_STEERING ||
        steering_ == -engine_params::SAFETY_STEERING)
        steering_ = 0.0;
  }

  // Create and publish Twist message
  twist.angular.z = steering_ * engine_params::STEERING_FACTOR;
  twist.linear.x = vel_;
  vel_pub_.publish(twist);
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "engine_node");
  ros::AsyncSpinner spinner(3);
  spinner.start();
  Engine eng;
  
  ros::waitForShutdown();
  return 0;
}
