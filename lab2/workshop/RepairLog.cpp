#include "RepairLog.h"
#include <iostream>

RepairLog::RepairLog(std::string name) : workshopName(name) {}

void RepairLog::addRepair(ServiceOrder* order) {
    repairHistory.push_back(order);
    std::cout << "Repair logged for order " << order->getOrderId() << std::endl;
}

void RepairLog::printLog() const {
    std::cout << "=== Repair Log for " << workshopName << " ===" << std::endl;
    for (const ServiceOrder* o : repairHistory) {
        std::cout << "  - Order " << o->getOrderId() << std::endl;
    }
}

std::vector<ServiceOrder*> RepairLog::getRepairsByDate(Date date) const {
    std::vector<ServiceOrder*> result = repairHistory;
    for(int i = 0; i < repairHistory.size(); i++){
        for(int j = i+1; j < repairHistory.size(); j++){
            if(result[j] < result[i])
                std::swap(result[j], result[i]);
        }
    }
    return result;
}

std::string RepairLog::getWorkshopName() const {
    return workshopName;
}