#include "ContactInfo.h"

ContactInfo::ContactInfo(std::string phone, std::string email, std::string addr)
        : phone(phone), email(email), address(addr) {}

std::string ContactInfo::getPhone() const {
    return phone;
}

std::string ContactInfo::getEmail() const {
    return email;
}

std::string ContactInfo::getAddress() const {
    return address;
}

void ContactInfo::updatePhone(std::string newPhone) {
    phone = newPhone;
}

void ContactInfo::updateEmail(std::string newEmail) {
    email = newEmail;
}