#ifndef RADIATOR_H
#define RADIATOR_H

#include <algorithm>

class Radiator {
private:
    double coolantVolume;
    double coreCondition;
    bool capSealed;
public:
    Radiator(double vol, double cond, bool cap);
    double coolRate(double flowRate);
    void flush();
    bool leakTest();
};
#endif

