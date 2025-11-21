#ifndef BODYWORK_H
#define BODYWORK_H
#include <string>
class Bodywork {
private:
    std::string damageType;
    double hoursNeeded;
    double metalsRepaired;
public:
    Bodywork(const std::string &d, double h, double m);
    double getHoursNeeded() const;
    void straighten();
    double weld(double amount);
    void estimateMaterial();
};
#endif

