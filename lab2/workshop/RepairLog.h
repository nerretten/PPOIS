#ifndef REPAIRLOG_H
#define REPAIRLOG_H

#include "../operations/ServiceOrder.h"
#include "../utilities/Date.h"
#include <string>
#include <vector>

class RepairLog {
private:
    std::vector<ServiceOrder*> repairHistory;
    std::string workshopName;

public:
    RepairLog(std::string name);
    void addRepair(ServiceOrder* order);
    void printLog() const;
    std::vector<ServiceOrder*> getRepairsByDate(Date date) const;
    std::string getWorkshopName() const;
};

#endif // REPAIRLOG_H