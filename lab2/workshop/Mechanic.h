#ifndef MECHANIC_H
#define MECHANIC_H

#include <string>
#include "../service/RepairOrder.h"
#include "../service/WorkItem.h"
#include "exceptions/MechanicNotAvailableException.h"
#include <stdexcept>
#include <numeric>
#include <vector>

class RepairOrder;
class Mechanic {
private:
    std::string name;
    int experienceYears;
    bool certified;
public:
    Mechanic(const std::string &n, int exp, bool cert);
    void performRepair(RepairOrder* order);
    double estimateTimeFor(RepairOrder* order);
};
#endif

