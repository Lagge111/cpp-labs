// Battery h file

#ifndef BATTERY_H
#define BATTERY_H

#include "Component.h"
#include <iostream>
#include <string>

class Battery : public Component
{
public:
    // Constructor
    Battery(std::string const name, double const voltage, Connection *const left, Connection *const right);
    // Desctructor
    ~Battery();
    double getVoltage();
    std::string name{name};

private:
    double current = 0;
    double const voltage;
};

#endif
