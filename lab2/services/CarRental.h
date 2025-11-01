#ifndef CARRENTAL_H
#define CARRENTAL_H

#include "../core/Car.h"
#include "../utilities/Date.h"
#include <string>

class CarRental {
private:
    Car* rentedCar;
    std::string renterName;
    Date startDate;
    Date endDate;
    double dailyRate;
    bool isReturned;

public:
    CarRental(Car* car, std::string renter, Date start, Date end, double rate);
    double calculateTotalCost() const;
    void returnCar();
    bool getIsReturned() const;
    std::string getRenterName() const;
};

#endif // CARRENTAL_H