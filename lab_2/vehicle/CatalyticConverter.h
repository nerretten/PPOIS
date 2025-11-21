#ifndef CATALYTIC_CONVERTER_H
#define CATALYTIC_CONVERTER_H

#include <algorithm>
class CatalyticConverter {
private:
    double efficiency;
    double temp;
    int sootLevel;
public:
    CatalyticConverter(double eff, double t, int soot);
    int getSootlevel() const;
    void setSootlevel(int soot);
    bool checkEfficiency();
    void clean();
    double expectedLifetimeYears() const;
};
#endif

