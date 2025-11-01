#include "Supplier.h"
#include <iostream>

Supplier::Supplier(std::string name, std::string contact, std::string addr)
        : name(name), contactInfo(contact), address(addr) {}

std::string Supplier::getName() const {
    return name;
}

std::string Supplier::getContactInfo() const {
    return contactInfo;
}

std::string Supplier::getAddress() const {
    return address;
}

void Supplier::placeOrder(std::string partId, int quantity) {
    std::cout << "Order placed with " << name << " for " << quantity << " of part " << partId << std::endl;
}