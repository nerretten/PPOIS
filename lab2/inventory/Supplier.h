#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>

class Supplier {
private:
    std::string name;
    std::string contactInfo;
    std::string address;

public:
    Supplier(std::string name, std::string contact, std::string addr);
    std::string getName() const;
    std::string getContactInfo() const;
    std::string getAddress() const;
    void placeOrder(std::string partId, int quantity);
};

#endif // SUPPLIER_H