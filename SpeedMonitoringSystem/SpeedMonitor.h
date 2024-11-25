#include "ICommunicatorInterface.h"
#include "ISpeedSensorInterface.h"
#include "ILogger.h"


class SpeedMonitor{
  private : int _speedThreshold , _minSpeed, _maxSpeed;
    ISpeedSensorInterface& _speedSensor;
    ICommunicatorInterface& _cloudCommunicator;
    ILoggerInterface& logger{};
  public:
          SpeedMonitor(int speedThreshold, int minspeed ,int maxspeed , BNFSpeedSensorInterface& speedSensor,
          IOTCloudCommunicatorInterface& cloudCommunicator ): _speedThreshold{speedThreshold} ,
          __minSpeed{minspeed}, _maxSpeed{maxspeed}, _speedSensor{speedSensor},
          _cloudCommunicator{cloudCommunicator} {}

          int getSpeedThreshold(){
            return _speedThreshold;
          }
          void setSpeedThreshold(int speedThreshold){
            _speedThreshold = speedThreshold;
          }

          void monitor();
};