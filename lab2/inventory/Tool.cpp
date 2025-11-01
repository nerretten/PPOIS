#include "Tool.h"
#include <iostream>

Tool::Tool(std::string id, std::string name, std::string type)
        : id(id), name(name), type(type), isAvailable(true) {}

void Tool::borrow() {
    if (!isAvailable) {
        std::cout << "Tool " << name << " is not available." << std::endl;
        return;
    }
    isAvailable = false;
    std::cout << "Tool " << name << " borrowed." << std::endl;
}

void Tool::returnTool() {
    isAvailable = true;
    std::cout << "Tool " << name << " returned." << std::endl;
}

bool Tool::getIsAvailable() const {
    return isAvailable;
}

std::string Tool::getName() const {
    return name;
}