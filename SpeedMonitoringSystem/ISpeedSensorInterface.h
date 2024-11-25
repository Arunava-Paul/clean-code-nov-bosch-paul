#ifndef ISPEEDSENSORINTERFACE_H
#define ISPEEDSENSORINTERFACE_H

class ISpeedSensorInterface {
public:
    virtual ~ISpeedSensorInterface() = default;
    virtual int getCurrentSpeed() = 0;
};

#endif // ISPEEDSENSORINTERFACE_H