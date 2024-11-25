int main(){
  BNFSpeedSensor speedSensorInstance;
  IOTCloudCommunicator cloudCommunicator;
  SpeedMonitor instance {10, 0, 40, speedSensorInstance, cloudCommunicator};
  instance.monitor();
  instance.monitor();
  instance.monitor();
  instance.monitor();
  instance.monitor();
}