#ifndef EXHAUST_H
#define EXHAUST_H
#include "CatalyticConverter.h"
class CatalyticConverter;
class Exhaust {
private:
    double length;
    double diameter;
    CatalyticConverter* cat;
public:
    Exhaust(double l, double d, CatalyticConverter* c);
    double getLength() const;
    double soundLevel(double rpm);
    void replaceSection(double meters);
    double backpressure(double flow);
};
#endif

