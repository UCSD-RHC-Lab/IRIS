/***************************************
 * Filename: engine.h
 * Students: Aayush Naik, Rebecca Kreitinger, Daniel Koohmarey
 * HRI Final Project
 * 
 * Description: This a header file for engine.cpp.
*******************************************/
#ifndef GUARD_ENGINE_H
#define GUARD_ENGINE_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <autobot_msgs/Command.h>
#include <autobot_msgs/Safety.h>

namespace engine_params {
  // Control parameters

  // Multiplier to the throttle supplied by interface
  double THROTTLE_FACTOR = 0.03;
  // Multiplier to the supplied supplied by interface
  double STEERING_FACTOR = 3.0;
  // The rate at which the velocity decays (every 100ms) when the brake is
  // pressed
  double BRAKE_DECAY = 0.3;  
  // The rate at which the velocity decays (every 100ms) due to simulated 
  // friction.
  double FRICTION_DECAY_FACTOR = 0.95;
  // Maximum permitted velocity
  double MAX_VEL = 0.25;
  // Degree of steering applied in order to avoid collision
  double SAFETY_STEERING = 0.4;
  // Velocity at or below which it is set to zero
  double MIN_THRESH = 0.02;
}


class Engine {
 public:
  Engine();
  void commandCallback(const autobot_msgs::Command::ConstPtr& command);
  void safetyCallback(const autobot_msgs::Safety::ConstPtr& msg);  
  void velocityCallback(const ros::TimerEvent& event);
 private:
  
  // Current acceleration and steering values
  double throttle_, steering_;
  // Whether or not the brake is pressed
  bool brake_;
  // Whether or not there is imminent danger of collision
  bool danger_;
  // Current velocity
  double vel_;
  // Heading and distance to collision
  double c_heading_, c_dist_;
  ros::NodeHandle nh_;
  // Subscriber to /autobot/commands
  ros::Subscriber command_sub_;
  // Subscriber to /autobot/safety
  ros::Subscriber safety_sub_;
  // Publisher to /cmd_vel_mux/teleop/input
  ros::Publisher vel_pub_;
  ros::Timer timer_;
};

#endif