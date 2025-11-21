#include "Wheel.h"



Wheel::Wheel(Tire* t, Brake* b): tire(t), brake(b), rpm(0) {}
void Wheel::rotate(double r){ rpm = r; }
double Wheel::getSpeedKmh(double radiusMeters) const {
    double revPerSec = rpm / 60.0;
    double mps = 2.0 * M_PI * radiusMeters * revPerSec;
    return mps * 3.6;
}
void Wheel::replaceTire(Tire* t){ tire = t; }

