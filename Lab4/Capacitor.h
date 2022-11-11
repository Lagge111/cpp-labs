// Capacitor h file

#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "Component.h"
#include "Connection.h"
#include <string>

class Capacitor : public Component
{
public:
    Capacitor(std::string const name, double const capacitance, Connection* const left, Connection* const right);
    void update(double const timeStep) override;
    double getCurrent() override;
    ~Capacitor();
private:
    double capacitance;
    double storedVoltage;
};

#endif
