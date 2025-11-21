#include "JobTimer.h"

JobTimer::JobTimer(int sec, bool run, int lap): secondsElapsed(sec), running(run), lastLap(lap) {}
void JobTimer::start(){
    running = true;
}
void JobTimer::stop(){
    running = false;
}
int JobTimer::lap(){
    lastLap = secondsElapsed;
    return lastLap;
}
void JobTimer::reset(){
    secondsElapsed = 0;
    lastLap = 0;
}
bool JobTimer::getRunning() const {
    return running;
}
