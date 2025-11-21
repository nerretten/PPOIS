#ifndef TECHNICIAN_SCHEDULE_H
#define TECHNICIAN_SCHEDULE_H
#include <string>
#include "Mechanic.h"
class Mechanic;
class TechnicianSchedule {
private:
    Mechanic* mech;
    std::string shiftStart;
    std::string shiftEnd;
public:
    TechnicianSchedule(Mechanic* m, const std::string &s, const std::string &e);
    bool isOnShift(const std::string &time) const;
    void swapShift(TechnicianSchedule* other);
    void extendShift(int minutes);
};
#endif

