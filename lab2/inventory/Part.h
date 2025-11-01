#ifndef PART_H
#define PART_H

#include <string>

class Part {
private:
    std::string id;
    std::string name;
    double price;
    int quantityInStock;

public:
    Part(std::string id, std::string name, double price, int qty = 0);
    void setQuantity(int qty);
    int getQuantity() const;
    double getPrice() const;
    std::string getName() const;
    void use(int qtyUsed);
};

#endif // PART_H