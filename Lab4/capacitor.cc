#include "Capacitor.h"
#include "Component.h"

using namespace std;

Capacitor::Capacitor(string const &name, double const capacitance, Connection *const left, Connection *const right)
    : Component(name, left, right), capacitance{capacitance}, storedCharge{0}, current{0}
{
}

void Capacitor::update(double const timeStep)
{
    double voltageToBeMoved{((abs(left->getVoltage() - right->getVoltage())) - storedCharge) * capacitance * timeStep};
    storedCharge += voltageToBeMoved;

    if (left->getVoltage() < right->getVoltage())
        moveVoltage(left, right, voltageToBeMoved);
    else
        moveVoltage(right, left, voltageToBeMoved);

    current = capacitance * (getVoltage() - storedCharge);
}

double Capacitor::getCurrent() const
{
    return current;
}