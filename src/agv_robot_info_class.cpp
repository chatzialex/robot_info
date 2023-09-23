#include "robot_info/agv_robot_info_class.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include <string>

void AGVRobotInfo::publish_data() {
  robotinfo_msgs::RobotInfo10Fields msg{};

  msg.data_field_01 = "robot_description: " + robot_description;
  msg.data_field_02 = "serial_number:" + serial_number;
  msg.data_field_03 = "ip_address: " + ip_address;
  msg.data_field_04 = "firmware_version:" + firmware_version;
  msg.data_field_05 = "maximum_payload:" + maximum_payload;
  msg.data_field_06 =
      "hydraulic_oil_temperature: " + hsm.getHydraulicOilTemperature();
  msg.data_field_07 =
      "hydraulic_oil_tank_fill_level: " + hsm.getHydraulicOilTankFillLevel();
  msg.data_field_08 =
      "hydraulic_oil_pressure: " + hsm.getHydraulicOilPressure();

  data_publisher.publish(msg);
}