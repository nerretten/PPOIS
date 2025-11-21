#include "Mechanic.h"

Mechanic::Mechanic(const std::string &n, int exp, bool cert)
        : name(n), experienceYears(exp), certified(cert) {}

void Mechanic::performRepair(RepairOrder* order) {
    if (!certified) {
        throw std::runtime_error("Mechanic not certified");
    }
    if (!order) {
        throw std::invalid_argument("RepairOrder is null");
    }

    for (auto* item : order->getItems()) {
        if (!item)
            continue;
    }

}

double Mechanic::estimateTimeFor(RepairOrder* order) {
    if (!order) {
        return 0.0;
    }

    double totalHours = 0.0;
    for (auto* item : order->getItems()) {
        if (item) {
            totalHours += item->getHours();
        }
    }

    double efficiency = std::max(0.7, 1.0 - (experienceYears * 0.05));
    return totalHours * efficiency;
}

