#include "Muffler.h"

Muffler::Muffler(double att, bool baf, int age): attenuationDb(att), bafflesOk(baf), ageYears(age) {}
double Muffler::reduceNoise(double rawDb){ return std::max(0.0, rawDb - attenuationDb); }
void Muffler::addBaffle(){ bafflesOk = true; attenuationDb += 2.0; }
bool Muffler::needsService() const { return ageYears > 10 || !bafflesOk; }
double Muffler::getAttenuationDb() const {return attenuationDb;}
