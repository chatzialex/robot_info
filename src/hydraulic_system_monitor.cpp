#include "robot_info/hydraulic_system_monitor.h"
#include <string>

const std::string &HydraulicSystemMonitor::getHydraulicOilTemperature() {
  return hydraulic_oil_temperature;
}
const std::string &HydraulicSystemMonitor::getHydraulicOilTankFillLevel() {
  return hydraulic_oil_tank_fill_level;
}
const std::string &HydraulicSystemMonitor::getHydraulicOilPressure() {
  return hydraulic_oil_pressure;
}

HydraulicSystemMonitor &
HydraulicSystemMonitor::setHydraulicOilTemperature(const std::string &value) {
  hydraulic_oil_temperature = value;
  return *this;
}
HydraulicSystemMonitor &
HydraulicSystemMonitor::setHydraulicOilTankFillLevel(const std::string &value) {
  hydraulic_oil_tank_fill_level = value;
  return *this;
}
HydraulicSystemMonitor &
HydraulicSystemMonitor::setHydraulicOilPressure(const std::string &value) {
  hydraulic_oil_pressure = value;
  return *this;
}