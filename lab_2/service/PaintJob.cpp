#include "PaintJob.h"

PaintJob::PaintJob(const std::string &c, double l, bool p): color(c), liters(l), primerApplied(p) {}
double PaintJob::estimateCost() const {
    return liters * 30.0 + (primerApplied ? 50.0 : 80.0);
}
void PaintJob::applyPrimer(){
    primerApplied = true;
}
void PaintJob::paintLayer(){
    liters = std::max(0.0, liters - 0.3);
}
double PaintJob::getLiters() const {
    return liters;
}
