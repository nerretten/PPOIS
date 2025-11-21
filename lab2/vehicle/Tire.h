#ifndef TIRE_H
#define TIRE_H
#include <string>
#include <algorithm>
class Tire {
private:
    std::string model;
    double pressure;
    int treadDepth;
public:
    Tire(const std::string &m, double p, int tread);
    void inflate(double add);
    bool needsReplacement() const;
    double wearAfterKm(int km);
};
#endif

