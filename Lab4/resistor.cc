#include "Resistor.h"
#include "Component.h"
#include <string>

using namespace std;

Resistor::Resistor(string const name, double const resistance, Connection *const left, Connection *const right)
    : Component(name, left, right), resistance{resistance}
{
}

void Resistor::update(double const timeStep)
{
    double voltageMoved{(getVoltage() / resistance) * timeStep};

    if (left->getVoltage() < right->getVoltage())
    {
        left->setVoltage(left->getVoltage() + voltageMoved);
        right->setVoltage(right->getVoltage() - voltageMoved);
    }
    else
    {
        right->setVoltage(right->getVoltage() + voltageMoved);
        left->setVoltage(left->getVoltage() - voltageMoved);
    }
}

double Resistor::getCurrent()
{
    return (getVoltage() / resistance);
}

Resistor::~Resistor()
{
}