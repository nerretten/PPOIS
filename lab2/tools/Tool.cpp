#include "Tool.h"

Tool::Tool(const std::string &n, bool cal, int used): name(n), calibrated(cal), timesUsed(used) {}
const std::string& Tool::getName() const { return name; }
void Tool::useFor(const std::string &job){
    timesUsed++;
    if (timesUsed >= 50) {
        calibrated = false;
    }
}
void Tool::calibrate(){
    calibrated = true;
}
bool Tool::needsCalibration() const {
    return !calibrated;
}

int Tool::getTimesUsed() const { return timesUsed; }
