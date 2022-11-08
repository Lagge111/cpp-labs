// Resistor component

#include "Resistor.h"
#include "Component.h"

using namespace std;

Resistor::Resistor(string const _name, double const _restistance, Connection *const _left, Connection *const _right) : Component()
{
}

double Resistor::getVoltage()
{
    // voltage is not declared in this scope
    return voltage;
}

void Resistor::update(double timeStep)
{
    // left and right are not declared in this scope
    double movedCharge{abs(left->getVoltage() - right.getVoltage())};
    if (left->getVoltage() > right->getVoltage())
    {
        left->setVoltage(calc2(movedCharge));
    }
    else
    {
        right->setVoltage(calc2(movedCharge));
    }
}

double calc2(double movedCharge)
{
    // resistance and timeStep are not declared in this scope
    return ((movedCharge / resistance) * timeStep);
}

Resistor::~Resistor()
{
}