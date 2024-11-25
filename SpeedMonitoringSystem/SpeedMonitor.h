#ifndef SPEEDMONITOR_H
#define SPEEDMONITOR_H

#include "ICommunicatorInterface.h"
#include "ISpeedSensorInterface.h"
#include "ILogger.h"

class SpeedMonitor {
private:
    int _speedThreshold, _minSpeed, _maxSpeed;
    ISpeedSensorInterface& _speedSensor;
    ICommunicatorInterface& _cloudCommunicator;
    ILoggerInterface& _logger;

public:
    SpeedMonitor(int speedThreshold, int minSpeed, int maxSpeed, ISpeedSensorInterface& speedSensor,
                 ICommunicatorInterface& cloudCommunicator, ILoggerInterface& logger)
        : _speedThreshold{speedThreshold}, _minSpeed{minSpeed}, _maxSpeed{maxSpeed},
          _speedSensor{speedSensor}, _cloudCommunicator{cloudCommunicator}, _logger{logger} {}

    void monitor();
};

#endif // SPEEDMONITOR_H