#ifndef TOOL_H
#define TOOL_H
#include <string>
class Tool {
private:
    std::string name;
    bool calibrated;
    int timesUsed;
public:
    Tool(const std::string &n, bool cal, int used);
    const std::string& getName() const;
    int getTimesUsed() const;
    void useFor(const std::string &job);
    void calibrate();
    bool needsCalibration() const;
};
#endif

