#include <iostream>
#include <random> 
#include <string>
using namespace std;

class IOTCloudCommunicator{
    public:
          int  pushMessage(string message){
              //Interact with internet and push the message to MessageQueue
            //if communiction succesfull return value from ramge {200 -400} status code otherwise returns errocode (400 - 500)
              std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> distr(200, 500);
                return distr(gen);
            
          }

};
class BNFSpeedSensor{
        public:
            int   getCurrentSpeed(){
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> distr(1, 100);
                return distr(gen);
            }
};

class SpeedMonitor{
    private : int _speedThreshold;
  
      public:
          SpeedMonitor(int speedThreshold): _speedThreshold{speedThreshold} {}
          void monitor(){
            if(_speedThreshold  < 1 || _speedThreshold > 100){
              cout<<"_speedThreshold value must be in the ramge {1-100} "<<_speedThreshold<<endl;
            }
              
            BNFSpeedSensor speedSensorInstance;
            IOTCloudCommunicator cloudCommuniccator;
            int currentSpeedInKmph=speedSensorInstance.getCurrentSpeed();
            
            cout<<"Current Speed In Kmph "<<currentSpeedInKmph<<endl;
            if(currentSpeedInKmph > _speedThreshold){
                  double mph = currentSpeedInKmph * 0.621371;
                  string message="Current Speed in Miles "+ to_string(mph);
                 int statusCode= cloudCommuniccator.pushMessage(message);
                  if(statusCode > 400){
                      //Log Message to Console
                       cout<<"Error In Communication Unable to Contact Server "<<message<< endl;
                  }
                 
            }
              
          }
};

int main(){
SpeedMonitor instance {10};
  instance.monitor();
  instance.monitor();
  instance.monitor();
  instance.monitor();
  instance.monitor();
}
