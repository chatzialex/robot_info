#include "robot_info/hydraulic_system_monitor.h"
#include "robot_info/robot_info_class.h"
#include <ros/node_handle.h>
#include <string>

struct AGVRobotInfoParams : public RobotInfoParams {
  std::string maximum_payload{};
  std::string hydraulic_oil_temperature{};
  std::string hydraulic_oil_tank_fill_level{};
  std::string hydraulic_oil_pressure{};
};

class AGVRobotInfo : public RobotInfo {
public:
  AGVRobotInfo(ros::NodeHandle *nh,
               const struct AGVRobotInfoParams &params = AGVRobotInfoParams{})
      : RobotInfo{nh, params}, maximum_payload{params.maximum_payload} {
    hsm.setHydraulicOilPressure(params.hydraulic_oil_pressure)
        .setHydraulicOilTankFillLevel(params.hydraulic_oil_tank_fill_level)
        .setHydraulicOilTemperature(params.hydraulic_oil_temperature);
  }
  void publish_data() override;

private:
  std::string maximum_payload;
  HydraulicSystemMonitor hsm{};
};