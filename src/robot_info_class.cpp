#include "robot_info/robot_info_class.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include <string>

void RobotInfo::publish_data() {
  robotinfo_msgs::RobotInfo10Fields msg{};

  msg.data_field_01 = "robot_description: " + robot_description;
  msg.data_field_02 = "serial_number:" + serial_number;
  msg.data_field_03 = "ip_address: " + ip_address;
  msg.data_field_04 = "firmware_version:" + firmware_version;

  data_publisher.publish(msg);
}

const std::string RobotInfo::kDataTopicName{"robot_info"};