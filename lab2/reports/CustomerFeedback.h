#ifndef CUSTOMERFEEDBACK_H
#define CUSTOMERFEEDBACK_H

#include <string>

class CustomerFeedback {
private:
    std::string customerName;
    int rating;
    std::string comment;
    bool resolved;

public:
    CustomerFeedback(std::string name, int rate, std::string comm);
    void resolve();
    int getRating() const;
    std::string getComment() const;
    std::string getCustomerName() const;
};

#endif // CUSTOMERFEEDBACK_H