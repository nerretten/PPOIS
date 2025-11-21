#ifndef PAINT_JOB_H
#define PAINT_JOB_H
#include <string>
class PaintJob {
private:
    std::string color;
    double liters;
    bool primerApplied;
public:
    PaintJob(const std::string &c, double l, bool p);
    double getLiters() const;
    double estimateCost() const;
    void applyPrimer();
    void paintLayer();
};
#endif

