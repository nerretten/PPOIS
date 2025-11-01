#ifndef QUALITYCONTROL_H
#define QUALITYCONTROL_H

#include "../operations/ServiceOrder.h"
#include "../employees/Mechanic.h"
#include <string>

class QualityControl {
private:
    std::string inspectorName;
    int inspectionRating; // 1-10
    ServiceOrder* inspectedOrder;
    std::string comments;

public:
    QualityControl(std::string inspector, ServiceOrder* order);
    void inspect();
    void setRating(int rating);
    void addComments(std::string comm);
    int getRating() const;
    std::string getComments() const;
    std::string getInspectorName() const;
};

#endif // QUALITYCONTROL_H