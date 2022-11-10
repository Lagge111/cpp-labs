// Resistor component

#include "Resistor.h"
#include "Component.h"
#include <iostream>
#include <string>

using namespace std;

Resistor::Resistor(string const name, int const resistance, Connection *const left, Connection *const right)
    : Component(name, left, right), resistance{resistance}
{
    cout << "Resistor created: " << getName() << endl;
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