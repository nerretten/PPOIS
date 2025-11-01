#ifndef MECHANIC_H
#define MECHANIC_H

#include <string>
#include <vector>

class Mechanic {
private:
    std::string name;
    std::string specialty;
    int yearsExperience;
    bool isAvailable;

public:
    Mechanic(std::string name, std::string spec, int exp);
    void assignToJob(std::string jobDescription);
    void completeJob();
    void takeBreak();
    std::string getName() const;
    std::string getSpecialty() const;
    bool getIsAvailable() const;
};

#endif // MECHANIC_H