#include "Exhaust.h"

Exhaust::Exhaust(double l, double d, CatalyticConverter* c): length(l), diameter(d), cat(c) {}
double Exhaust::soundLevel(double rpm) { return rpm / 100.0 + (diameter * 2.0); }
void Exhaust::replaceSection(double meters) { length = std::max(0.1, length - meters); }
double Exhaust::backpressure(double flow){ return flow / (diameter * length); }
double Exhaust::getLength() const {return length;}
