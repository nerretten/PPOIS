#include "Transmission.h"

Transmission::Transmission(int g, bool aut, double fluid): gears(g), automatic(aut), fluidLevel(fluid) {}
bool Transmission::shiftUp() {
    if (fluidLevel < 0.2) return false;
    return true;
}
bool Transmission::shiftDown(){ return true; }
double Transmission::leakRate(){ return (1.0 - fluidLevel) * 0.05; }

