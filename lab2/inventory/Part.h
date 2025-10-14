#ifndef LAB2_PART_H
#define LAB2_PART_H
#include <string>

class Part{
private:
    std::string name;
    double price;
    std::string manufacturer;
public:
    Part(const std::string& name, double price, const std::string& manufacturer);
    const std::string& get_name() const;
    double get_price() const;
    const std::string& get_manufacturer() const;
    void set_name(const std::string& s);
    void set_price(double x);
    void set_manufacturer(const std::string& s);
};

#endif
