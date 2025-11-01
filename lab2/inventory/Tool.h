#ifndef TOOL_H
#define TOOL_H

#include <string>

class Tool {
private:
    std::string id;
    std::string name;
    std::string type;
    bool isAvailable;

public:
    Tool(std::string id, std::string name, std::string type);
    void borrow();
    void returnTool();
    bool getIsAvailable() const;
    std::string getName() const;
};

#endif // TOOL_H