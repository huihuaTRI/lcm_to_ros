#include "ros/ros.h"

#include <lcm/lcm-cpp.hpp>

#include "drake/lcmt_hsr_sim_status.hpp"

// A loop to continuously publish lcm lcmt_hsr_sim_status message. This
// executable can be used together with `hsr_sim_status_channel_republisher` to
// confirm the published LCM message can be converted to the corresponding ROS
// message as expected.
int main(int argc, char **argv) {
  ros::init(argc, argv, "lcm_sim_status_publisher");
  ros::NodeHandle nh("hsr");

  lcm::LCM lcm("udpm://239.255.76.67:7667?ttl=0");
  if (!lcm.good())
    return 1;

  drake::lcmt_hsr_sim_status lcm_msg;

  lcm_msg.utime = 1;
  lcm_msg.num_joints = 2;
  lcm_msg.joint_name.resize(lcm_msg.num_joints);
  lcm_msg.joint_position.resize(lcm_msg.num_joints);
  lcm_msg.joint_velocity.resize(lcm_msg.num_joints);
  lcm_msg.joint_torque.resize(lcm_msg.num_joints);

  // lcm message publishing loop.
  ros::Rate rate(100);
  while (ros::ok()) {
    lcm.publish("hsr_sim_status_channel", &lcm_msg);
    rate.sleep();
  }

  ros::shutdown();

  return 0;
}