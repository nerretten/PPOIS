#ifndef PAINTJOB_H
#define PAINTJOB_H

#include "Service.h"
#include "../core/Car.h"
#include <string>

class PaintJob : public Service {
private:
    Car* car;
    std::string color;
    double paintAreaSqM;
    bool isComplete;

public:
    PaintJob(std::string desc, Car* c, std::string col, double area);
    void perform();
    void schedule();
    std::string getColor() const;
    bool getIsComplete() const;
};

#endif // PAINTJOB_H