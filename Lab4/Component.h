
// Weird fucking error with #ifndef COMPONENT_H.
// The error doesn't show up in the terminal when running the code,
// it's just there
#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Component
{
public:
    Component();
    ~Component();
    std::string getName();

private:
};

#endif