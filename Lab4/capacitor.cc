
#include "Capacitor.h"
#include "Component.h"

using namespace std;

Capacitor::Capacitor(string const name, double const capacitance, Connection *const left, Connection *const right)
    : Component(name, left, right), capacitance{capacitance}, storedCharge{0}, current{0}
{
}

void Capacitor::update(double const timeStep)
{
    double movedCharge{((abs(left->getVoltage() - right->getVoltage())) - storedCharge) * capacitance * timeStep};
    storedCharge += movedCharge;

    if (left->getVoltage() < right->getVoltage())
        changeVoltage(left, right, movedCharge);
    else
        changeVoltage(right, left, movedCharge);

    current = capacitance * (getVoltage() - storedCharge);
}

double Capacitor::getCurrent()
{
    return current;
}

Capacitor::~Capacitor()
{
}

void Capacitor::changeVoltage(Connection *lowest, Connection *highest, double movedCharge)
{
    lowest->setVoltage(lowest->getVoltage() + movedCharge);
    highest->setVoltage(highest->getVoltage() - movedCharge);
}