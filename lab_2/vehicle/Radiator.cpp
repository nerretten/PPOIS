#include "Radiator.h"

Radiator::Radiator(double vol, double cond, bool cap): coolantVolume(vol), coreCondition(cond), capSealed(cap) {}
double Radiator::coolRate(double flowRate) { return flowRate * coreCondition * 5.0; }
void Radiator::flush(){ coreCondition = std::min(1.0, coreCondition + 0.1); }
bool Radiator::leakTest(){ return capSealed && coolantVolume > 0.1; }

