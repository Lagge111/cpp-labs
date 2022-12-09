#include "Resistor.h"
#include "Component.h"
#include <string>

using namespace std;

Resistor::Resistor(string const& name, double const resistance, Connection *const left, Connection *const right)
    : Component(name, left, right), resistance{resistance}, current{0}
{
}

void Resistor::update(double const timeStep)
{
    double voltageToBeMoved{(getVoltage() / resistance) * timeStep};

    if (left->getVoltage() < right->getVoltage())
        moveVoltage(left, right, voltageToBeMoved);
    else
        moveVoltage(right, left, voltageToBeMoved);

    current = getVoltage() / resistance;
}

double Resistor::getCurrent() const
{
    return current;
}
