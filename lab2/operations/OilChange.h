#ifndef OILCHANGE_H
#define OILCHANGE_H

#include "Service.h"
#include "../core/Car.h"
#include "../inventory/Part.h"
#include <string>

class OilChange : public Service {
private:
    Car* car;
    Part* oilFilter;
    Part* engineOil;
    double oilQuantityLiters;

public:
    OilChange(std::string desc, Car* c, Part* filter, Part* oil, double qty);
    void perform();
    void schedule();
    double getOilQuantity() const;
};

#endif // OILCHANGE_H