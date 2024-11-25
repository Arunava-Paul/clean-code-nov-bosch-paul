#include "ILogger.h"
class ConsoleLogger : public ILoggerInterface
{
public:
    template <typename T>
    void write(const T& message) override{
        std::cout << message;
    }
};