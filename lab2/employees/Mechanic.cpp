#include "Mechanic.h"
#include <iostream>

Mechanic::Mechanic(std::string name, std::string spec, int exp)
        : name(name), specialty(spec), yearsExperience(exp), isAvailable(true) {}

void Mechanic::assignToJob(std::string jobDescription) {
    if (!isAvailable) {
        std::cout << "Mechanic " << name << " is not available." << std::endl;
        return;
    }
    std::cout << "Mechanic " << name << " assigned to: " << jobDescription << std::endl;
    isAvailable = false;
}

void Mechanic::completeJob() {
    isAvailable = true;
    std::cout << "Mechanic " << name << " completed the job." << std::endl;
}

void Mechanic::takeBreak() {
    isAvailable = false;
    std::cout << "Mechanic " << name << " is on break." << std::endl;
}

std::string Mechanic::getName() const {
    return name;
}

std::string Mechanic::getSpecialty() const {
    return specialty;
}

bool Mechanic::getIsAvailable() const {
    return isAvailable;
}