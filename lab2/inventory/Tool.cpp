#include "Tool.h"

Tool::Tool(const std::string& name): name(name), is_available(true){}
void Tool::use(){
    is_available = false;
}
void Tool::return_tool(){
    is_available = true;
}
bool Tool::get_is_available() const {return is_available;}