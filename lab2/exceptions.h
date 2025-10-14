#ifndef LAB2_EXCEPTIONS_H
#define LAB2_EXCEPTIONS_H

#include <stdexcept>

class InvalidCarException: public std::exception{
    const char* what() const noexcept override;
};

class PartNotFound: public std:: exception{
    const char* what() const noexcept override;
};

class InvalidDateException: public std::exception{
    const char* what() const noexcept override;
};

class ToolUnavailableException: public std::exception{
    const char* what() const noexcept override;
};

class WarehouseEmptyException: public std::exception{
    const char* what() const noexcept override;
};

class ServiceNotApplicableException: public std::exception{
    const char* what() const noexcept override;
};


#endif //LAB2_EXCEPTIONS_H
