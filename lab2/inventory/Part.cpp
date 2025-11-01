#include "Part.h"
#include "../exceptions.h"
#include <iostream>

Part::Part(std::string id, std::string name, double price, int qty)
        : id(id), name(name), price(price), quantityInStock(qty) {}

void Part::setQuantity(int qty) {
    quantityInStock = qty;
}

int Part::getQuantity() const {
    return quantityInStock;
}

double Part::getPrice() const {
    return price;
}

std::string Part::getName() const {
    return name;
}

void Part::use(int qtyUsed){
    if (quantityInStock < qtyUsed) {
        throw PartNotInStockException("Not enough parts in stock: " + name);
    }
    quantityInStock -= qtyUsed;
    std::cout << "Used " << qtyUsed << " of part: " << name << std::endl;
}