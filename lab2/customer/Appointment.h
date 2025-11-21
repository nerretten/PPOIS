#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include "exceptions/InvalidAppointmentException.h"
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <string>
#include "../workshop/Bay.h"
#include "../exceptions/InvalidAppointmentException.h"
#include <stdexcept>

class Bay;
class Appointment {
private:
    static bool isValidDateTime(const std::string& dt);
    static int timeToMinutes(const std::string& dt);
    std::string datetime;
    Bay* bay;
    int durationMinutes;
public:
    Appointment(const std::string &dt, Bay* b, int dur);
    Bay* getBay() const;
    bool conflictsWith(const Appointment* other) const;
    void reschedule(const std::string &newDt);

};
#endif

