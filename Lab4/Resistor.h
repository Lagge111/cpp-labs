
#ifndef RESISTOR_H
#define RESISTOR_H

#include "Component.h"
#include "Connection.h"

class Resistor : public Component
{
public:
    Resistor(std::string _name, double const _resistance, Connection *const _left, Connection *const _right);
    ~Resistor();
    void update(double timeStep);
    double getVoltage();

private:
    double current;
    double resistance;
    double voltage;
    double calc2(double movedCharge);
};

#endif
