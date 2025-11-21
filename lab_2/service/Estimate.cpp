#include "Estimate.h"

Estimate::Estimate(int id_, const std::string &d, double h): id(id_), description(d), laborHours(h) {}
double Estimate::totalEstimate(double laborRate){
    return laborHours * laborRate;
}
void Estimate::addLabor(double hours){
    laborHours += hours;
}
void Estimate::reduce(double percent){
    laborHours *= (1.0 - percent/100.0);
}
double Estimate::getLabourHours() const {
    return laborHours;
}
