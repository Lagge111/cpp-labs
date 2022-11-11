// Resistor h file

#ifndef RESISTOR_H
#define RESISTOR_H

#include "Component.h"
#include "Connection.h"
#include <string>

class Resistor : public Component
{
public:
    Resistor(std::string name, int const resistance, Connection *const left, Connection *const right);
    ~Resistor();
    void update(double timeStep) override;
    //double getVoltage() override;
    double getCurrent() override;
private:
    double voltage;
    int resistance;
};

#endif
