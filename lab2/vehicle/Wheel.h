#ifndef WHEEL_H
#define WHEEL_H
#include "Tire.h"
#include "Brake.h"
#include <cmath>
class Tire;
class Brake;
class Wheel {
private:
    Tire* tire;
    Brake* brake;
    double rpm;
public:
    Wheel(Tire* t, Brake* b);
    void rotate(double r);
    double getSpeedKmh(double radiusMeters) const;
    void replaceTire(Tire* t);
};
#endif

