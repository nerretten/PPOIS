#ifndef ENGINE_H
#define ENGINE_H

#include <string>

class Engine {
private:
    std::string type;
    int horsepower;
    bool isRunning;

public:
    Engine(std::string t, int hp);
    void start();
    void stop();
    bool getIsRunning() const;
    int getHorsepower() const;
};

#endif // ENGINE_H