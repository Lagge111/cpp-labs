// Component h file

// Weird fucking error with #ifndef COMPONENT_H.
// The error doesn't show up in the terminal when running the code,
// it's just there
#ifndef COMPONENT_H
#define COMPONENT_H

#include "Connection.h"
#include <string>

class Component
{
public:
    Component(std::string const name, Connection *const left, Connection *const right);
    ~Component();
    virtual void update(double const timeStep);
    double getVoltage();
    virtual double getCurrent();
    std::string getName();
protected:
    Connection *left;
    Connection *right;
    std::string name;
};

#endif