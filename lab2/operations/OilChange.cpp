#include "OilChange.h"
#include <iostream>
#include "../exceptions.h"

OilChange::OilChange(std::string desc, Car* c, Part* filter, Part* oil, double qty)
        : Service(desc), car(c), oilFilter(filter), engineOil(oil), oilQuantityLiters(qty) {}

void OilChange::perform() {
    try {
        oilFilter->use(1);
        engineOil->use(static_cast<int>(oilQuantityLiters));
        std::cout << "Oil change performed on car " << car->getVin() << std::endl;
    } catch (PartNotInStockException& e) {
        std::cout << "Error during oil change: " << e.what() << std::endl;
    }
}

void OilChange::schedule() {
    std::cout << "Oil change scheduled for car " << car->getVin() << std::endl;
}

double OilChange::getOilQuantity() const {
    return oilQuantityLiters;
}