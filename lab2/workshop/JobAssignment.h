#ifndef JOBASSIGNMENT_H
#define JOBASSIGNMENT_H

#include "../employees/Mechanic.h"
#include "../operations/ServiceOrder.h"
#include "../utilities/Date.h"
#include <string>

class JobAssignment {
private:
    Mechanic* mechanic;
    ServiceOrder* order;
    Date assignmentDate;
    std::string status;

public:
    JobAssignment(Mechanic* mech, ServiceOrder* ord, Date date);
    void startWork();
    void completeWork();
    void cancel();
    std::string getStatus() const;
    std::string getAssignmentDetails() const;
};

#endif // JOBASSIGNMENT_H