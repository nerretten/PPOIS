#include "CarRental.h"
#include <iostream>

CarRental::CarRental(Car* car, std::string renter, Date start, Date end, double rate)
        : rentedCar(car), renterName(renter), startDate(start), endDate(end), dailyRate(rate), isReturned(false) {}

double CarRental::calculateTotalCost() const {
    return (endDate-startDate+1) * dailyRate;
}

void CarRental::returnCar() {
    isReturned = true;
    std::cout << "Car " << rentedCar->getVin() << " returned by " << renterName << std::endl;
}

bool CarRental::getIsReturned() const {
    return isReturned;
}

std::string CarRental::getRenterName() const {
    return renterName;
}