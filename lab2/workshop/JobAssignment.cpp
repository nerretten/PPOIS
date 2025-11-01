#include "JobAssignment.h"
#include <iostream>

JobAssignment::JobAssignment(Mechanic* mech, ServiceOrder* ord, Date date)
        : mechanic(mech), order(ord), assignmentDate(date), status("Assigned") {}

void JobAssignment::startWork() {
    status = "In Progress";
    mechanic->assignToJob("Job Assignment " + order->getOrderId());
    std::cout << "Mechanic " << mechanic->getName() << " started work on order " << order->getOrderId() << std::endl;
}

void JobAssignment::completeWork() {
    status = "Completed";
    mechanic->completeJob();
    std::cout << "Mechanic " << mechanic->getName() << " completed work on order " << order->getOrderId() << std::endl;
}

void JobAssignment::cancel() {
    status = "Cancelled";
    mechanic->takeBreak(); // Условно — освобождаем механика
    std::cout << "Job assignment for order " << order->getOrderId() << " cancelled." << std::endl;
}

std::string JobAssignment::getStatus() const {
    return status;
}

std::string JobAssignment::getAssignmentDetails() const {
    return "Mechanic: " + mechanic->getName() + ", Order: " + order->getOrderId() + ", Status: " + status;
}