#ifndef COMPONENT_H
#define COMPONENT_H

#include "Connection.h"
#include <string>

class Component
{
public:
    Component(std::string const name, Connection *const left, Connection *const right);
    virtual void update(double const timeStep);
    double getVoltage();
    virtual double getCurrent();
    std::string getName();
    void moveVoltage(Connection *lowest, Connection *highest, double movedCharge);
    ~Component();

protected:
    Connection *left;
    Connection *right;
    std::string name;
};

#endif