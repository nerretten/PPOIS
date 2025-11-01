#ifndef TRANSMISSION_H
#define TRANSMISSION_H

#include <string>

class Transmission {
private:
    std::string type;
    int gear;
    bool isEngaged;

public:
    Transmission(std::string type);
    void shiftUp();
    void shiftDown();
    int getGear() const;
    std::string getType() const;
};

#endif // TRANSMISSION_H