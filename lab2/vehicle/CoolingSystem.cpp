#include "CoolingSystem.h"


CoolingSystem::CoolingSystem(Radiator* r, Thermostat* t, double flow): radiator(r), thermostat(t), pumpFlow(flow) {}
double CoolingSystem::regulate(double engineTemp) {
    thermostat->operate(engineTemp);
    if (thermostat->shouldOpen()) return radiator->coolRate(pumpFlow);
    return 0.0;
}
void CoolingSystem::flushAll(){ radiator->flush(); }
bool CoolingSystem::checkLeaks(){ return radiator->leakTest(); }

