#include "BNFSpeedSensor.cpp"
#include "IOTCloudCommunicator.cpp"
#include "ConsoleLogger.cpp"
#include "SpeedMonitor.h"

int main() {
    BNFSpeedSensor speedSensorInstance;
    IOTCloudCommunicator cloudCommunicator;
    ConsoleLogger logger;
    SpeedMonitor instance{10, 0, 40, speedSensorInstance, cloudCommunicator, logger};
    instance.monitor();
    instance.monitor();
    instance.monitor();
    instance.monitor();
    instance.monitor();
    return 0;
}