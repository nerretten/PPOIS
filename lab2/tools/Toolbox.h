#ifndef TOOLBOX_H
#define TOOLBOX_H
#include <vector>
#include <iostream>
#include "Tool.h"

class Tool;
class Toolbox {
private:
    std::vector<Tool*> tools;
    int ownerId;
    std::string location;
public:
    Toolbox(int owner, const std::string &loc);
    void addTool(Tool* t);
    Tool* findTool(const std::string &name);
    void inventory();
    const std::vector<Tool*>& getTools() const { return tools; }
};
#endif

