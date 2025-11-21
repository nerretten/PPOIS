#include "Appointment.h"

Appointment::Appointment(const std::string &dt, Bay* b, int dur)
        : datetime(dt), bay(b), durationMinutes(dur) {
    if (dur <= 0) {
        throw InvalidAppointmentException();
    }
    if (!isValidDateTime(dt)) {
        throw InvalidAppointmentException();
    }
}

bool Appointment::conflictsWith(const Appointment* other) const {
    if (!other || other->bay != this->bay) {
        return false;
    }

    int start1 = timeToMinutes(datetime);
    int end1 = start1 + durationMinutes;

    int start2 = timeToMinutes(other->datetime);
    int end2 = start2 + other->durationMinutes;

    return !(end1 <= start2 || end2 <= start1);
}

void Appointment::reschedule(const std::string &newDt) {
    if (!isValidDateTime(newDt)) {
        throw InvalidAppointmentException();
    }
    datetime = newDt;
}

Bay* Appointment::getBay() const {
    return bay;
}

bool Appointment::isValidDateTime(const std::string& dt) {
    if (dt.length() != 16) return false;
    if (dt[4] != '-' || dt[7] != '-' || dt[10] != ' ' || dt[13] != ':') return false;

    for (int i = 0; i < 16; ++i) {
        if (i == 4 || i == 7 || i == 10 || i == 13) continue;
        if (!std::isdigit(dt[i])) return false;
    }

    int year = std::stoi(dt.substr(0, 4));
    int month = std::stoi(dt.substr(5, 2));
    int day = std::stoi(dt.substr(8, 2));
    int hour = std::stoi(dt.substr(11, 2));
    int minute = std::stoi(dt.substr(14, 2));

    if (year < 2020 || month < 1 || month > 12 || day < 1 || day > 31) return false;
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59) return false;

    return true;
}

int Appointment::timeToMinutes(const std::string& dt) {
    int hour = std::stoi(dt.substr(11, 2));
    int minute = std::stoi(dt.substr(14, 2));
    return hour * 60 + minute;
}