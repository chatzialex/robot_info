#include "robot_info/agv_robot_info_class.h"
#include "ros/node_handle.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "agv_robot_info_node");
  ros::NodeHandle node_handle{};

  AGVRobotInfoParams robot_info_params{};
  robot_info_params.robot_description = "Mir100";
  robot_info_params.serial_number = "567A359";
  robot_info_params.ip_address = "169.254.5.180";
  robot_info_params.firmware_version = "3.5.8";
  robot_info_params.maximum_payload = "100 Kg";
  robot_info_params.hydraulic_oil_temperature = "45C";
  robot_info_params.hydraulic_oil_tank_fill_level = "100%";
  robot_info_params.hydraulic_oil_pressure = "250 bar";

  AGVRobotInfo robot_info{&node_handle, robot_info_params};
  ros::Rate loop_rate(0.5);
  while (ros::ok()) {
    robot_info.publish_data();
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}