#ifndef CONTACTINFO_H
#define CONTACTINFO_H

#include <string>

class ContactInfo {
private:
    std::string phone;
    std::string email;
    std::string address;

public:
    ContactInfo(std::string phone, std::string email, std::string addr);
    std::string getPhone() const;
    std::string getEmail() const;
    std::string getAddress() const;
    void updatePhone(std::string newPhone);
    void updateEmail(std::string newEmail);
};

#endif // CONTACTINFO_H