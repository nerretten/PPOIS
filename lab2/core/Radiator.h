#ifndef RADIATOR_H
#define RADIATOR_H

#include <string>

class Radiator {
private:
    std::string id;
    double coolantLevel;
    bool isLeaking;

public:
    Radiator(std::string id, double level = 100.0);
    void checkCoolant();
    void refillCoolant(double amount);
    double getCoolantLevel() const;
    bool getIsLeaking() const;
};

#endif // RADIATOR_H