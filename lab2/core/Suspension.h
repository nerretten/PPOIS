#ifndef SUSPENSION_H
#define SUSPENSION_H

#include <string>

class Suspension {
private:
    std::string type;
    double shockAbsorberWear;

public:
    Suspension(std::string type, double wear = 0.0);
    void inspect();
    void replaceShockAbsorbers();
    double getShockAbsorberWear() const;
    std::string getType() const;
};

#endif // SUSPENSION_H