#include "CustomerFeedback.h"
#include <iostream>

CustomerFeedback::CustomerFeedback(std::string name, int rate, std::string comm)
        : customerName(name), rating(rate), comment(comm), resolved(false) {}

void CustomerFeedback::resolve() {
    resolved = true;
    std::cout << "Feedback from " << customerName << " resolved." << std::endl;
}

int CustomerFeedback::getRating() const {
    return rating;
}

std::string CustomerFeedback::getComment() const {
    return comment;
}

std::string CustomerFeedback::getCustomerName() const {
    return customerName;
}