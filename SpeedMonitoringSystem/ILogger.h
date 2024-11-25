#ifndef ILOGGER_H
#define ILOGGER_H

class ILoggerInterface {
public:
    virtual ~ILoggerInterface() = default;
    template <typename T>
    virtual void write(const T& message) = 0;
};

#endif // ILOGGER_H
