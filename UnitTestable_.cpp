#include <iostream>
#include <random> 
#include <string>
using namespace std;

class IOTCloudCommunicatorInterface{
    public:
          virtual int  pushMessage(string message)=0;
};
class BNFSpeedSensorInterface{
        public:
            virtual int   getCurrentSpeed()=0;
};

class IOTCloudCommunicator:public IOTCloudCommunicatorInterface{
    public:
          int  pushMessage(string message)  override{
              //Interact with internet and push the message to MessageQueue
            //if communiction succesfull return value from ramge {200 -400} status code otherwise returns errocode (400 - 500)
              std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> distr(200, 500);
                return distr(gen);
            
          }

};
class BNFSpeedSensor:public BNFSpeedSensorInterface{
        public:
            int   getCurrentSpeed override(){
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> distr(1, 100);
                return distr(gen);
            }
};

class Logger {
public:
    template <typename T>
    Logger& operator<<(const T& message) {
        std::cout << message<<std::endl;
        return *this;
    }
};

class SpeedConverter{
    public:
        SpeedMonitor(int speedThreshold): _speedThreshold{speedThreshold} {}

        double kmphToMph(int kmph){
            return kmph * 0.621371;
        }
        bool isSpeedThresholdValid(int speedThreshold, int minSpeed, int maxSpeed){
            return speedThreshold >= minSpeed && speedThreshold <= maxSpeed;
        }
        //any more conversion methods
};

class SpeedMonitor{
    private : int _speedThreshold , _minSpeed, _maxSpeed;
    BNFSpeedSensorInterface& _speedSensor;
    IOTCloudCommunicatorInterface& _cloudCommunicator;
    Logger logger{};
    SpeedConverter _speedConverter{};
      public:
          SpeedMonitor(int speedThreshold,BNFSpeedSensorInterface& speedSensor,
          IOTCloudCommunicatorInterface& cloudCommunicator ): _speedThreshold{speedThreshold} , _speedSensor{speedSensor},
          _cloudCommunicator{cloudCommunicator} {}


          void monitor(){
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
                      logger <<"Error In Communication Unable to Contact Server "<<message;
                  }
                 
            }
              
          }
};

int main(){
  BNFSpeedSensor speedSensorInstance;
  IOTCloudCommunicator cloudCommuniccator;
  SpeedMonitor instance {10 , speedSensorInstance, cloudCommunicator};
  instance.monitor();
  instance.monitor();
  instance.monitor();
  instance.monitor();
  instance.monitor();
}
