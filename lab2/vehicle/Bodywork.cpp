#include "Bodywork.h"

Bodywork::Bodywork(const std::string &d, double h, double m): damageType(d), hoursNeeded(h), metalsRepaired(m) {}
void Bodywork::straighten(){ hoursNeeded *= 0.8; }
double Bodywork::weld(double amount){ metalsRepaired += amount; return metalsRepaired; }
void Bodywork::estimateMaterial(){ metalsRepaired += 0.1; }
double Bodywork::getHoursNeeded() const{return hoursNeeded;}
