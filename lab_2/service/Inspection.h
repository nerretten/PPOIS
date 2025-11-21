#ifndef INSPECTION_H
#define INSPECTION_H
#include <string>
class Inspection {
private:
    std::string inspector;
    bool passed;
    int issuesFound;
public:
    Inspection(const std::string &ins, bool p, int issues);
    void run();
    void failWith(int n);
    std::string report() const;
};
#endif

