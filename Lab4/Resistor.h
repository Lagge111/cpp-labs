#ifndef RESISTOR_H
#define RESISTOR_H

#include "Component.h"
#include "Connection.h"
#include <string>

class Resistor : public Component
{
public:
    Resistor(std::string name, double const resistance, Connection *const left, Connection *const right);
    ~Resistor();
    void update(double const timeStep) override;
    double getCurrent() override;

private:
    double voltage;
    double resistance;
};

#endif
