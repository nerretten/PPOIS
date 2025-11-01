#include "QualityControl.h"
#include <iostream>

QualityControl::QualityControl(std::string inspector, ServiceOrder* order)
        : inspectorName(inspector), inspectionRating(0), inspectedOrder(order), comments("") {}

void QualityControl::inspect() {
    std::cout << "Quality control inspection by " << inspectorName << " for order " << inspectedOrder->getOrderId() << std::endl;
    if (inspectedOrder->getServices().size() > 0) {
        inspectionRating = 8;
        comments = "All services completed satisfactorily.";
    } else {
        inspectionRating = 5;
        comments = "No services found.";
    }
    std::cout << "Rating: " << inspectionRating << "/10" << std::endl;
    std::cout << "Comments: " << comments << std::endl;
}

void QualityControl::setRating(int rating) {
    inspectionRating = rating;
}

void QualityControl::addComments(std::string comm) {
    comments = comm;
}

int QualityControl::getRating() const {
    return inspectionRating;
}

std::string QualityControl::getComments() const {
    return comments;
}

std::string QualityControl::getInspectorName() const {
    return inspectorName;
}