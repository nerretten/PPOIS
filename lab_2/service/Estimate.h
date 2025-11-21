#ifndef ESTIMATE_H
#define ESTIMATE_H
#include <string>
class Estimate {
private:
    int id;
    std::string description;
    double laborHours;
public:
    Estimate(int id_, const std::string &d, double h);
    double getLabourHours() const;
    double totalEstimate(double laborRate);
    void addLabor(double hours);
    void reduce(double percent);
};
#endif

