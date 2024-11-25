#include "ICommunicatorInterface.h"
#include <random>
#include <string>

class IOTCloudCommunicator : public ICommunicatorInterface {
public:
    int pushMessage(string message) override {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(200, 500);
        return distr(gen);
    }
};