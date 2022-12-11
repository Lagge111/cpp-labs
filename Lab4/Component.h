#ifndef COMPONENT_H
#define COMPONENT_H

#include "Connection.h"
#include <string>

class Component
{
public:
    Component(std::string const &name, Connection *const left, Connection *const right);
    virtual void update(double const /* timeStep */) = 0;
    double getVoltage() const;
    virtual double getCurrent() const;
    std::string getName() const;
    void moveVoltage(Connection *lowest, Connection *highest, double movedCharge);
    virtual ~Component() = default;

protected:
    std::string name;
    Connection *left;
    Connection *right;
};

#endif