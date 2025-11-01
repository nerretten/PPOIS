#ifndef WHEELALIGNMENT_H
#define WHEELALIGNMENT_H

#include "Service.h"
#include "../core/Car.h"
#include <string>

class WheelAlignment : public Service {
private:
    Car* car;
    double toeIn;
    double camber;
    double caster;
    bool isAligned;

public:
    WheelAlignment(std::string desc, Car* c, double toe, double cam, double cast);
    void perform();
    void schedule();
    bool getIsAligned() const;
};

#endif