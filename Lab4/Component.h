// Component h file

// Weird fucking error with #ifndef COMPONENT_H.
// The error doesn't show up in the terminal when running the code,
// it's just there
#ifndef COMPONENT_H
#define COMPONENT_H

#include "Connection.h"
#include <iostream>
#include <string>

class Component
{
public:
    Component(std::string const name, Connection *const left, Connection *const right);
    ~Component();
    std::string name;
    virtual void update(double const timeStep);
    double getVoltage();
    double getCurrent();
    std::string getName();
protected:
    Connection *left;
    Connection *right;
};

#endif