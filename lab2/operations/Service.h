#ifndef SERVICE_H
#define SERVICE_H

#include <string>

class Service {
protected:
    std::string description;
    bool isCompleted;

public:
    Service(std::string desc);
    virtual void perform() = 0;
    virtual void schedule() = 0;
    bool getIsCompleted() const;
    std::string getDescription() const;
};

#endif // SERVICE_H