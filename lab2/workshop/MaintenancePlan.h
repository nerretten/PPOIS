#ifndef MAINTENANCEPLAN_H
#define MAINTENANCEPLAN_H

#include "../core/Car.h"
#include "../utilities/Date.h"
#include <vector>
#include <string>

class MaintenancePlan {
private:
    Car* car;
    Date nextServiceDate;
    std::vector<std::string> scheduledServices;
    double estimatedCost;

public:
    MaintenancePlan(Car* c, Date next, std::vector<std::string> services, double cost);
    void addService(std::string service);
    void updateNextServiceDate(Date newDate);
    void printPlan() const;
    std::string getCarVin() const;
    Date getNextServiceDate() const;
};

#endif // MAINTENANCEPLAN_H