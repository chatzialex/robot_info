#pragma once
#include <string>

class HydraulicSystemMonitor {
public:
  const std::string &getHydraulicOilTemperature();
  const std::string &getHydraulicOilTankFillLevel();
  const std::string &getHydraulicOilPressure();

  HydraulicSystemMonitor &setHydraulicOilTemperature(const std::string &value);
  HydraulicSystemMonitor &
  setHydraulicOilTankFillLevel(const std::string &value);
  HydraulicSystemMonitor &setHydraulicOilPressure(const std::string &value);

private:
  std::string hydraulic_oil_temperature{};
  std::string hydraulic_oil_tank_fill_level{};
  std::string hydraulic_oil_pressure{};
};