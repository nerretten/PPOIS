#include "Tire.h"


Tire::Tire(const std::string &m, double p, int tread): model(m), pressure(p), treadDepth(tread) {}
void Tire::inflate(double add){ pressure += add; if (pressure>5.0) pressure=5.0; }
bool Tire::needsReplacement() const { return treadDepth < 2; }
double Tire::wearAfterKm(int km) {
    int wear = km / 10000;
    int newDepth = std::max(0, treadDepth - wear);
    return newDepth;
}

