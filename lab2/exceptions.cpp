#include "exceptions.h"

const char* InvalidCarException::what() const noexcept {
    return "Invalid car data";
}

const char* PartNotFound::what() const noexcept{
    return "There is no such part";
}

const char* InvalidDateException::what() const noexcept {
    return "Invalid date";
}

const char* ToolUnavailableException::what() const noexcept {
    return "Tool is used now";
}

const char* WarehouseEmptyException::what() const noexcept {
    return "Warehouse is empty";
}

const char* ServiceNotApplicableException::what() const noexcept {
    return "Service cann't be applied to car";
}


