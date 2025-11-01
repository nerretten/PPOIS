#include "Service.h"

Service::Service(std::string desc) : description(desc), isCompleted(false) {}

bool Service::getIsCompleted() const {
    return isCompleted;
}

std::string Service::getDescription() const {
    return description;
}