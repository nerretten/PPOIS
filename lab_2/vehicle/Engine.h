#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include "Battery.h"
#include "Sensor.h"
#include "../exceptions/DiagnosticFailureException.h"
#include <cmath>
#include <stdexcept>
class Battery;
class Sensor;
class Engine {
private:
    int cylinders;
    double displacement;
    Battery* battery;
public:
    Engine(int cyl, double disp, Battery* b);
    bool start();
    double computeFuelConsumption(double hours, double rpm);
    double checkCompression();
    void replaceBattery(Battery* b);
};
#endif

