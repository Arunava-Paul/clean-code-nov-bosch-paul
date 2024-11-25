#include <iostream>
#include <random>
#include <string>
using namespace std;

class IOTCloudCommunicatorInterface {
  public:
    virtual int pushMessage(string message) = 0;
    virtual ~IOTCloudCommunicatorInterface() = default;
};

class BNFSpeedSensorInterface {
  public:
    virtual int getCurrentSpeed() = 0;
    virtual ~BNFSpeedSensorInterface() = default;
};

class IOTCloudCommunicator : public IOTCloudCommunicatorInterface {
  public:
    int pushMessage(string message) override {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(200, 500);
        return distr(gen);
    }
};

class BNFSpeedSensor : public BNFSpeedSensorInterface {
  public:
    int getCurrentSpeed() override {
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
        std::cout << message << std::endl;
        return *this;
    }
};

class SpeedConverter {
  public:
    double kmphToMph(int kmph) {
        return kmph * 0.621371;
    }
    bool isSpeedThresholdValid(int speedThreshold, int minSpeed, int maxSpeed) {
        return speedThreshold >= minSpeed && speedThreshold <= maxSpeed;
    }
};

class SpeedMonitor {
  private:
    int _speedThreshold, _minSpeed, _maxSpeed;
    BNFSpeedSensorInterface& _speedSensor;
    IOTCloudCommunicatorInterface& _cloudCommunicator;
    Logger logger{};
    SpeedConverter _speedConverter{};

  public:
    SpeedMonitor(int speedThreshold, BNFSpeedSensorInterface& speedSensor, IOTCloudCommunicatorInterface& cloudCommunicator)
      : _speedThreshold{speedThreshold}, _speedSensor{speedSensor}, _cloudCommunicator{cloudCommunicator}, _minSpeed{0}, _maxSpeed{200} {}

    void monitor() {
        if (!_speedConverter.isSpeedThresholdValid(_speedThreshold, _minSpeed, _maxSpeed)) {
            logger << "_speedThreshold value must be in the range " << _minSpeed << "-" << _maxSpeed << ": " << _speedThreshold;
            return;
        }
        int currentSpeedInKmph = _speedSensor.getCurrentSpeed();
        logger << "Current Speed In Kmph " << currentSpeedInKmph;

        if (currentSpeedInKmph > _speedThreshold) {
            double mph = _speedConverter.kmphToMph(currentSpeedInKmph);
            string message = "Current Speed in Miles " + to_string(mph);
            int statusCode = _cloudCommunicator.pushMessage(message);
            if (statusCode > 400) {
                logger << "Error In Communication Unable to Contact Server " << message;
            }
        }
    }
};

class MockSpeedSensor : public BNFSpeedSensorInterface {
  public:
    int getCurrentSpeed() override {
        return 50; // Return a fixed value for testing
    }
};

class MockCloudCommunicator : public IOTCloudCommunicatorInterface {
  public:
    int pushMessage(string message) override {
        cout << "Mock pushMessage called with: " << message << endl;
        return 200; // Return a fixed value for testing
    }
};

int main() {
    MockSpeedSensor mockSensor;
    MockCloudCommunicator mockCommunicator;
    SpeedMonitor monitor(40, mockSensor, mockCommunicator);
    monitor.monitor();
    return 0;
}
