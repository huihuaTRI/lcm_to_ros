#include "ros/ros.h"

#include <lcm/lcm-cpp.hpp>

#include "lcm_to_ros/lcmt_hsr_sim_command.h"

// A loop to continuously publish ros hsr_sim_command message. This executable
// can be used together with `hsr_sim_command_channel_republisher` to confirm
// the published ROS message can be converted to the corresponding lcm message
// as expected.
int main(int argc, char **argv) {
  ros::init(argc, argv, "lcm_sim_status_publisher");
  ros::NodeHandle nh;

  auto ros_command_pub =
      ros::Publisher(nh.advertise<lcm_to_ros::lcmt_hsr_sim_command>(
          "hsr_sim_command_channel", 1000));

  lcm_to_ros::lcmt_hsr_sim_command ros_msg;

  ros_msg.utime = 1;
  ros_msg.num_joints = 2;
  ros_msg.joint_name.resize(ros_msg.num_joints);
  ros_msg.joint_position.resize(ros_msg.num_joints);
  ros_msg.joint_velocity.resize(ros_msg.num_joints);

  // ros message publishing loop.
  ros::Rate rate(100);
  while (ros::ok()) {
    ros_command_pub.publish(ros_msg);
    rate.sleep();
  }

  ros::shutdown();

  return 0;
}