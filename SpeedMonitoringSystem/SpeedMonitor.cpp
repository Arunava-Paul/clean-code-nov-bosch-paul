#include <iostream>
#include <random> 
#include <string>
#include "SpeedMonitor.h"

using namespace std;



class SpeedConverter{
    public:
        SpeedConverter() {}

        double kmphToMph(int kmph){
            return kmph * 0.621371;
        }
        bool isSpeedThresholdValid(int speedThreshold, int minSpeed, int maxSpeed){
            return speedThreshold >= minSpeed && speedThreshold <= maxSpeed;
        }
        //any more conversion methods
};

void SpeedMonitor::monitor() {
    SpeedConverter _speedConverter;
    if (!_speedConverter.isSpeedThresholdValid(_speedThreshold, _minSpeed, _maxSpeed)) {
        _logger.write("_speedThreshold value must be in the range " + std::to_string(_minSpeed) + "-" + std::to_string(_maxSpeed) + ": " + std::to_string(_speedThreshold));
        return;
    }
    int currentSpeedInKmph = _speedSensor.getCurrentSpeed();
    _logger.write("Current Speed In Kmph " + std::to_string(currentSpeedInKmph));

    if (currentSpeedInKmph > _speedThreshold) {
        double mph = _speedConverter.kmphToMph(currentSpeedInKmph);
        string message = "Current Speed in Miles " + to_string(mph);
        int statusCode = _cloudCommunicator.pushMessage(message);
        if (statusCode > 400) {
            _logger.write("Error In Communication Unable to Contact Server " + message);
        }
    }
}


