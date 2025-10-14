#ifndef LAB2_TOOL_H
#define LAB2_TOOL_H
#include <string>

class Tool{
private:
    std::string name;
    bool is_available;
public:
    Tool(const std::string& name);
    void use();
    void return_tool();
    bool get_is_available() const;
};


#endif
