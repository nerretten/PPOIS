#ifndef WORKSHOP_EXCEPTION_H
#define WORKSHOP_EXCEPTION_H
#include <exception>
#include <string>
class WorkshopException : public std::exception {
protected:
    std::string msg;
public:
    explicit WorkshopException(const std::string &m): msg(m) {}
    const char* what() const noexcept override { return msg.c_str(); }
};
#endif

