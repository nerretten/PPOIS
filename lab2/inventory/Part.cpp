#include "Part.h"

Part::Part(const std::string &sku_, const std::string &name_, double price): sku(sku_), name(name_), unitPrice(price) {}
double Part::priceWithTax(double taxRate) const {
    return unitPrice * (1.0 + taxRate);
}
bool Part::isCompatibleWith(const std::string &model) const {
    return model.find(name) != std::string::npos;
}

