#include <autobot/safety.h>

Safety::Safety(): frame_num_(0) {
  pc2_sub_ = 
    nh_.subscribe<sensor_msgs::PointCloud2>("camera/depth/points", 1,
      &Safety::depthCallback, this);
  
  safety_pub_ = nh_.advertise<autobot_msgs::Safety>("autobot/safety", 10);
}

void Safety::depthCallback(const sensor_msgs::PointCloud2ConstPtr& input) {
  autobot_msgs::Safety safe_msg;
  if (frame_num_ == 0) {
    pcl::PointCloud<pcl::PointXYZ> cloud;
    pcl::fromROSMsg(*input, cloud);
    double heading = 0.0, distance = 0.0;
    int num_points = 0;

    // Sum distance and headings for points within COLLISION_DIST_THRESH
    for (pcl::PointXYZ p: cloud) {
      if (p.z < safety_params::COLLISION_DIST_THRESH) {
        distance += p.z;
        heading += p.x;
        num_points++;
      }
    }

    // If the number of points is greater than COLLISION_NUM_THRESH, then
    // declare danger and compute additional information
    if (num_points > safety_params::COLLISION_NUM_THRESH) {
      heading /= num_points;
      distance /= num_points;
      safe_msg.danger = true;
      safe_msg.heading = heading;
      safe_msg.distance = distance;
    }
  }
  // Publish safety message     
  safety_pub_.publish(safe_msg);
  // Update frame number
  frame_num_ = (frame_num_ + 1) % safety_params::FRAME_SKIP;
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "safety_node");
  Safety safety;

  ros::spin();
  return 0;
}
