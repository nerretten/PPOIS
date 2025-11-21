#ifndef STARTER_H
#define STARTER_H

#include <algorithm>

class Starter {
private:
    int torqueNm;
    int cycles;
    bool solenoidOk;
public:
    Starter(int torque, int cycles_, bool solenoid);
    void setSycles(int cycles);
    bool crank();
    void service();
    double expectedLifeLeft() const;
};
#endif

