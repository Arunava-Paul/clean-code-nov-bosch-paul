#include "ISpeedSensorInterface.h"

class BNFSpeedSensor:public ISpeedSensorInterface{
        public:
            int   getCurrentSpeed override(){
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> distr(1, 100);
                return distr(gen);
            }
};