#ifndef LAB2_SERVICE_H
#define LAB2_SERVICE_H
#include <string>

class Service{
private:
    std::string name;
    double base_price;
    int estimated_minutes;
public:
    Service(const std::string& name, double base_price, int estimated_minutes);
    const std::string& get_name() const;
    double get_base_price() const;
    int get_estimated_minutes() const;
    void set_name(const std::string& s);
    void set_base_price(double x);
    void set_estimated_minutes(int x);
};

#endif
