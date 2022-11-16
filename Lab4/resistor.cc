#include "Resistor.h"
#include "Component.h"
#include <string>

using namespace std;

Resistor::Resistor(string const name, double const resistance, Connection *const left, Connection *const right)
    : Component(name, left, right), resistance{resistance}, current{0}
{
}

void Resistor::update(double const timeStep)
{
    double movedCharge{(getVoltage() / resistance) * timeStep};

    if (left->getVoltage() < right->getVoltage())
        changeVoltage(left, right, movedCharge);
    else
        changeVoltage(right, left, movedCharge);

    current = getVoltage() / resistance;
}

double Resistor::getCurrent()
{
    return current;
}

void Resistor::changeVoltage(Connection *lowest, Connection *highest, double movedCharge)
{
    lowest->setVoltage(lowest->getVoltage() + movedCharge);
    highest->setVoltage(highest->getVoltage() - movedCharge);
}

Resistor::~Resistor()
{
}