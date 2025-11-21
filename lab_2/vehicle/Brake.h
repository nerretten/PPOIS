#ifndef BRAKE_H
#define BRAKE_H

#include <algorithm>

class Brake {
private:
    double padThickness;
    double fluidQuality;
    bool absEnabled;
public:
    Brake(double pad, double fq, bool abs);
    double apply(double force);
    void bleed(double amount);
    bool checkPads() const;
};
#endif

