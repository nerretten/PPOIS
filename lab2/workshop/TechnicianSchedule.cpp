#include "TechnicianSchedule.h"
#include "Mechanic.h"
#include <stdexcept>
#include <sstream>

static int timeToMinutes(const std::string& timeStr) {
    if (timeStr.length() != 5 || timeStr[2] != ':') {
        throw std::invalid_argument("Invalid time format. Expected HH:MM");
    }
    int hours = std::stoi(timeStr.substr(0, 2));
    int minutes = std::stoi(timeStr.substr(3, 2));
    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59) {
        throw std::invalid_argument("Invalid time values");
    }
    return hours * 60 + minutes;
}

TechnicianSchedule::TechnicianSchedule(Mechanic* m, const std::string &s, const std::string &e)
        : mech(m), shiftStart(s), shiftEnd(e) {
    if (!m) {
        throw std::invalid_argument("Mechanic cannot be null");
    }
    int startMin = timeToMinutes(shiftStart);
    int endMin = timeToMinutes(shiftEnd);
    if (endMin <= startMin) {
        throw std::invalid_argument("Shift end must be after start");
    }
}

bool TechnicianSchedule::isOnShift(const std::string &time) const {
    int t = timeToMinutes(time);
    int start = timeToMinutes(shiftStart);
    int end = timeToMinutes(shiftEnd);
    return t >= start && t <= end;
}

void TechnicianSchedule::swapShift(TechnicianSchedule* other) {
    if (!other) {
        throw std::invalid_argument("Other schedule cannot be null");
    }
    std::swap(shiftStart, other->shiftStart);
    std::swap(shiftEnd, other->shiftEnd);
}

void TechnicianSchedule::extendShift(int minutes) {
    if (minutes <= 0) {
        throw std::invalid_argument("Extension must be positive");
    }
    int currentEnd = timeToMinutes(shiftEnd);
    currentEnd += minutes;

    if (currentEnd > 23 * 60 + 59) {
        currentEnd = 23 * 60 + 59;
    }

    int hours = currentEnd / 60;
    int mins = currentEnd % 60;
    std::ostringstream ss;
    ss << (hours < 10 ? "0" : "") << hours << ":"
       << (mins < 10 ? "0" : "") << mins;
    shiftEnd = ss.str();
}