#ifndef MUFFLER_H
#define MUFFLER_H

#include <algorithm>

class Muffler {
private:
    double attenuationDb;
    bool bafflesOk;
    int ageYears;
public:
    Muffler(double att, bool baf, int age);
    double getAttenuationDb() const;
    double reduceNoise(double rawDb);
    void addBaffle();
    bool needsService() const;
};
#endif

