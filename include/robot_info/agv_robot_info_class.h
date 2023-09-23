#include "robot_info/robot_info_class.h"
#include <ros/node_handle.h>
#include <string>

struct AGVRobotInfoParams : public RobotInfoParams {
  std::string maximum_payload{};
};

class AGVRobotInfo : public RobotInfo {
public:
  AGVRobotInfo(ros::NodeHandle *nh,
               const struct AGVRobotInfoParams &params = AGVRobotInfoParams{})
      : RobotInfo{nh, params}, maximum_payload{params.maximum_payload} {}
  void publish_data() override;

private:
  std::string maximum_payload;
};