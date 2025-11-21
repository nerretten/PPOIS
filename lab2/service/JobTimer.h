#ifndef JOB_TIMER_H
#define JOB_TIMER_H
class JobTimer {
private:
    int secondsElapsed;
    bool running;
    int lastLap;
public:
    JobTimer(int sec, bool run, int lap);
    bool getRunning() const;
    void start();
    void stop();
    int lap();
    void reset();
};
#endif

