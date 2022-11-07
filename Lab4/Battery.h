// Battery h file

#ifndef BATTERY_H
#define BATTERY_H

#include "Component.h"

class Battery : public Component
{
public:
    // Constructor
    Battery(std::string const _name, double const _voltage, Connection* const _left, Connection* const _right);
    // Desctructor
    ~Battery();
    double getVoltage();
private:
    void setLeft();
    double current = 0;
    double voltage;
    Connection* left = _left;
};

#endif
