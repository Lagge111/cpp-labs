// Resistor component

#include "Resistor.h"
#include "Component.h"

using namespace std;

Resistor::Resistor(std::string _name, double const _restistance, Connection* const _left, Connection* const _right) : Component
{

}

double getVoltage()
{
    return voltage;
}

void Resistor update(double timeStep)
{
    double movedCharge{abs(left->getVoltage() - right.getVoltage())}; 
    if (left->getVoltage() > right->getVoltage()) {
        left->setVoltage(calc2(movedCharge));
    } else {
        right->setVoltage(calc2(movedCharge));
    }
}

double calc2(double movedCharge) {
    return (movedCharge / resistance) * timeStep
}

~Resistor()
{

}