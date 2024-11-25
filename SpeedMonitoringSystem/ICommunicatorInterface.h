#ifndef ICOMMUNICATORINTERFACE_H
#define ICOMMUNICATORINTERFACE_H

#include <string>
using namespace std;

class ICommunicatorInterface {
public:
    virtual ~ICommunicatorInterface() = default;
    virtual int pushMessage(string message) = 0;
};

#endif // ICOMMUNICATORINTERFACE_H