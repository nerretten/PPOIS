#include "Brake.h"

Brake::Brake(double pad, double fq, bool abs): padThickness(pad), fluidQuality(fq), absEnabled(abs) {}
double Brake::apply(double force) {
    double decel = force * (padThickness / 10.0) * (fluidQuality);
    return decel;
}
void Brake::bleed(double amount){ fluidQuality = std::min(1.0, fluidQuality + amount); }
bool Brake::checkPads() const { return padThickness > 2.0; }

