// Battery h file

#ifndef BATTERY_H
#define BATTERY_H

#include "Component.h"
#include <iostream>
#include <string>

using namespace std;

class Battery : public Component
{
public:
    // Constructor
    Battery(string const name, double const voltage, Connection *const left, Connection *const right);
    // Desctructor
    ~Battery();
    double getVoltage();
    string name{name};

private:
    double current = 0;
    double const voltage;
};

#endif
