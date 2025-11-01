#ifndef SERVICESTATISTICS_H
#define SERVICESTATISTICS_H

#include "../operations/ServiceOrder.h"
#include <vector>
#include <string>

class ServiceStatistics {
private:
    std::vector<ServiceOrder*> orders;
    int totalServices;
    double averageCost;

public:
    ServiceStatistics(std::vector<ServiceOrder*> ord);
    void computeStats();
    int getTotalServices() const;
    double getAverageCost() const;
    void printStats() const;
};

#endif // SERVICESTATISTICS_H