#ifndef LAB2_CLIENT_H
#define LAB2_CLIENT_H
#include <string>

class Client{
private:
    std::string name;
    std::string phone;
public:
    Client(const std::string& name, const std::string& phone);
    const std::string& get_name() const;
    const std::string& get_phone() const;
    void set_name(const std::string& s);
    void set_phone(const std::string& s);
};


#endif
