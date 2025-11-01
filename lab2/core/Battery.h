#ifndef BATTERY_H
#define BATTERY_H

#include <string>

class Battery {
private:
    std::string id;
    int voltage;
    int capacityAh;
    bool isCharged;

public:
    Battery(std::string id, int volt, int cap);
    void charge();
    void discharge();
    bool getIsCharged() const;
    int getVoltage() const;
    int getCapacityAh() const;
};

#endif // BATTERY_H