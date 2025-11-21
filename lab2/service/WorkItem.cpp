#include "WorkItem.h"

WorkItem::WorkItem(const std::string &d, Part* p, double h): description(d), part(p), hours(h) {}

double WorkItem::getHours() const{
    return hours;
}

double WorkItem::estimateCost() const {
    double partCost = part ? part->priceWithTax(0.2) : 0.0;
    return partCost + hours * 25.0;
}
void WorkItem::extendHours(double h){
    hours += h;
}
void WorkItem::requirePart(Part* p){
    part = p;
}

