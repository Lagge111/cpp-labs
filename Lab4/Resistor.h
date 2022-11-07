// Resistor h file

#ifndef RESISTOR_H
#define RESISTOR_H

#include "Component.h"

class Resistor : public Component
{
public:
    Resistor();
    ~Resistor();
    void update(double timeStep);
    double getVoltage();
private:
    double current{_current};
    double resistance{_restistance};
    double calc2();
};

#endif
