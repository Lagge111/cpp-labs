// Resistor component

#include "Resistor.h"
#include "Component.h"

using namespace std;

Resistor::Resistor(string const name, double const resistance, Connection *const left, Connection *const right) : Component()
{
}

double Resistor::getVoltage()
{
    // voltage is undefined
    return voltage;
}

void Resistor::update(double timeStep)
{
    Connection *left{left};
    Connection *right{right};
    double LV = left->getVoltage();
    double RV = right->getVoltage();
    double resistance{resistance};

    double movedCharge{abs(LV - RV)};

    if (left->getVoltage() > right->getVoltage())
    {
        left->setVoltage(((movedCharge / resistance) * timeStep));
    }
    else
    {
        right->setVoltage(((movedCharge / resistance) * timeStep));
    }
}

Resistor::~Resistor()
{
}