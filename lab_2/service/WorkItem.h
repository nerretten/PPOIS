#ifndef WORK_ITEM_H
#define WORK_ITEM_H
#include <string>
#include "../inventory/Part.h"
class Part;
class WorkItem {
private:
    std::string description;
    Part* part;
    double hours;
public:
    WorkItem(const std::string &d, Part* p, double h);
    double getHours() const;
    double estimateCost() const;
    void extendHours(double h);
    void requirePart(Part* p);
};
#endif

