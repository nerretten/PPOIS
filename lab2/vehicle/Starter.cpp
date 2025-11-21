#include "Starter.h"

Starter::Starter(int torque, int cycles_, bool solenoid): torqueNm(torque), cycles(cycles_), solenoidOk(solenoid) {}
bool Starter::crank() {
    if (!solenoidOk) return false;
    cycles++;
    return cycles < 10000;
}
void Starter::service(){
    cycles = 0; solenoidOk = true;
}
double Starter::expectedLifeLeft() const {
    return std::max(0.0, 1.0 - cycles / 10000.0);
}
void Starter::setSycles(int cycles) {
    cycles = cycles;
}
