#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "Component.h"
#include "Connection.h"
#include <string>

class Capacitor : public Component
{
public:
    Capacitor(std::string const name, double const capacitance, Connection *const left, Connection *const right);
    void update(double const timeStep) override;
    double getCurrent() const override;
    ~Capacitor();

private:
    double const capacitance;
    double storedCharge;
    double current;
};

#endif
