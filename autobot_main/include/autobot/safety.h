/***************************************
 * Filename: safety.h
 * Students: Aayush Naik, Rebecca Kreitinger, Daniel Koohmarey
 * HRI Final Project
 * 
 * Description: This a header file for safety.cpp.
*******************************************/

#ifndef GUARD_SAFETY_H
#define GUARD_SAFETY_H

#include <autobot_msgs/Safety.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/PointCloud2.h>
#include <string>


namespace safety_params {
  // Distance beyond which points are not considered for collision
  double COLLISION_DIST_THRESH = 0.7;
  // Minimum number of points detected within COLLISION_DIST_THRESH to declare 
  // a collision
  double COLLISION_NUM_THRESH = 500;
  // One depth frame is processed every FRAME_SKIP frames
  int FRAME_SKIP = 1;
}


class Safety {
 public:
  Safety();
 private:
  void depthCallback(const sensor_msgs::PointCloud2ConstPtr&);
  // Current frame number
  int frame_num_;
  // The latest received point cloud
  pcl::PointCloud<pcl::PointXYZ> cloud_;
  ros::NodeHandle nh_;
  // Subscribes to /camera/depth/points
  ros::Subscriber pc2_sub_;
  // Publishes a Safety message corresponding to the collision point
  ros::Publisher safety_pub_;  
};

#endif