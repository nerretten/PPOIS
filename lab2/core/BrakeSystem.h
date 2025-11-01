#ifndef BRAKESYSTEM_H
#define BRAKESYSTEM_H

#include <string>

class BrakeSystem {
private:
    std::string type;
    double padWearPercentage;
    bool isFunctional;

public:
    BrakeSystem(std::string t, double wear = 0.0);
    void inspect();
    void replacePads();
    double getPadWear() const;
    bool getIsFunctional() const;
};

#endif // BRAKESYSTEM_H