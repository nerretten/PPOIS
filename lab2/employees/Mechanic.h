#ifndef LAB2_MECHANIC_H
#define LAB2_MECHANIC_H
#include <string>
#include "../exceptions.h"
#include "../inventory/Tool.h"

class Mechanic{
private:
    std::string name;
    std::string specialization;
    int experiance_years;
public:
    Mechanic(const std::string& name, const std::string& specialization, int experiance_years);
    const std::string& get_name() const;
    const std::string& get_specialization() const;
    const int get_experiance_years() const;
    void set_name(const std::string& s);
    void set_specialization(const std::string& s);
    void set_experiance_years(int x);
    void use_tool(Tool& t);
};


#endif
