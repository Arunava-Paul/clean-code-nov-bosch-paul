#include <iostream>
#include <random> 
#include <string>

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




void SpeedMonitor::monitor(){
            SpeedConverter _speedConverter;
            if(_speedConverter.isSpeedThresholdValid(_speedThreshold, _minSpeed, _maxSpeed)){
              logger <<"_speedThreshold value must be in the ramge"<<__minSpeed<<"-"<<_maxSpeed<<": "<<_speedThreshold;
            }
            int currentSpeedInKmph=_speedSensor.getCurrentSpeed();            
            logger << "Current Speed In Kmph " << currentSpeedInKmph;

            if(currentSpeedInKmph > _speedThreshold){
                  double mph = unitConverter.kmphToMph(currentSpeedInKmph);
                  string message="Current Speed in Miles "+ to_string(mph);
                  int statusCode= cloudCommuniccator.pushMessage(message);
                  if(statusCode > 400){
                      //Log Message to Console
 //                     logger <<"Error In Communication Unable to Contact Server "<<message;
                  }
                 
            }
              
          }


