#ifndef HEADLIGHT_H
#define HEADLIGHT_H

#include <string>

class Headlight {
private:
    std::string id;
    std::string type;
    bool isOn;

public:
    Headlight();
    Headlight(std::string id, std::string type);
    void turnOn();
    void turnOff();
    bool getIsOn() const;
    std::string getType() const;
};

#endif // HEADLIGHT_H