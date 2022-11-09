// Resistor h file

#ifndef RESISTOR_H
#define RESISTOR_H

#include "Component.h"
#include "Connection.h"

class Resistor : public Component
{
public:
    Resistor(std::string name, double const resistance, Connection *const left, Connection *const right);
    ~Resistor();
    void update(double timeStep);
    double getVoltage();

private:
    double voltage;
    int resistance;
};

#endif
