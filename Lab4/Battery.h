#ifndef BATTERY_H
#define BATTERY_H

#include "Component.h"
#include "Connection.h"

class Battery : public Component
{
public:
    Battery(std::string const name, double const voltage, Connection *const left, Connection *const right);
    double getCurrent() override;
    void update(double const timeStep) override;
    ~Battery();

private:
    double const current = 0;
    double const voltage;
};

#endif
