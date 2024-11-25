#include "ILogger.h"
#include <iostream>

class ConsoleLogger : public ILoggerInterface {
public:
    template <typename T>
    void write(const T& message) override {
        std::cout << message << std::endl;
    }
};