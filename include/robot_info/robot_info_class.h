#pragma once

#include "robotinfo_msgs/RobotInfo10Fields.h"
#include "ros/forwards.h"
#include <ros/node_handle.h>
#include <ros/publisher.h>
#include <string>

struct RobotInfoParams {
  std::string robot_description{};
  std::string serial_number{};
  std::string ip_address{};
  std::string firmware_version{};
};

class RobotInfo {
public:
  RobotInfo(ros::NodeHandle *nh,
            const struct RobotInfoParams &params = RobotInfoParams{})
      : data_publisher{nh->advertise<robotinfo_msgs::RobotInfo10Fields>(
            kDataTopicName, 1000)},
        robot_description{params.robot_description},
        serial_number{params.serial_number}, ip_address{params.ip_address},
        firmware_version{params.firmware_version} {}
  virtual ~RobotInfo() = default;
  virtual void publish_data();

protected:
  ros::Publisher data_publisher{};
  std::string robot_description{};
  std::string serial_number{};
  std::string ip_address{};
  std::string firmware_version{};

private:
  static const std::string kDataTopicName;
};