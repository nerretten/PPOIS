#ifndef PART_H
#define PART_H
#include <string>
class Part {
private:
    std::string sku;
    std::string name;
    double unitPrice;
public:
    Part(const std::string &sku_, const std::string &name_, double price);
    double priceWithTax(double taxRate) const;
    bool isCompatibleWith(const std::string &model) const;
};
#endif

