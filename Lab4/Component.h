// Component h file

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
    virtual double getVoltage();
    virtual double getCurrent();
    std::string getName();
protected:
    Connection *left;
    Connection *right;
    std::string name;
};

#endif