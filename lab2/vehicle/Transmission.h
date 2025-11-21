#ifndef TRANSMISSION_H
#define TRANSMISSION_H
class Transmission {
private:
    int gears;
    double fluidLevel;
    bool automatic;
public:
    Transmission(int g, bool aut, double fluid);
    bool shiftUp();
    bool shiftDown();
    double leakRate();
};
#endif

