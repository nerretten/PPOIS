//
// Created by Timur N on 14.10.25.
//

#include "Client.h"

Client::Client(const std::string& name, const std::string& phone):name(name), phone(phone){}
const std::string& Client::get_name() const {return name;}
const std::string& Client::get_phone() const {return phone;}
void Client::set_name(const std::string& s) {name = s;}
void Client::set_phone(const std::string& s) { phone = s;}
