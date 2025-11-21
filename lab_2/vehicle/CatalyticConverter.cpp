#include "CatalyticConverter.h"

CatalyticConverter::CatalyticConverter(double eff, double t, int soot): efficiency(eff), temp(t), sootLevel(soot) {}
bool CatalyticConverter::checkEfficiency(){ return efficiency > 0.6 && sootLevel < 50; }
void CatalyticConverter::clean(){ sootLevel = std::max(0, sootLevel - 30); }
double CatalyticConverter::expectedLifetimeYears() const { return 8.0 * efficiency; }
int CatalyticConverter::getSootlevel() const{return sootLevel;}
void CatalyticConverter::setSootlevel(int soot) {sootLevel = soot;}
