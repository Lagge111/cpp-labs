
#include "Capacitor.h"
#include "Component.h"

using namespace std;

Capacitor::Capacitor(string const name, double const capacitance, Connection *const left, Connection *const right)
    : Component(name, left, right), capacitance{capacitance}, storedCharge{0}
{
}

void Capacitor::update(double const timeStep)
{
    double voltageDiff{abs(left->getVoltage() - right->getVoltage())};
    double movedCharge{(voltageDiff - storedCharge) * capacitance * (timeStep)};
    int direction{((left->getVoltage() <= right->getVoltage()) ? 1 : -1)};

    left->setVoltage(left->getVoltage() + (direction * movedCharge));
    right->setVoltage(right->getVoltage() - (direction * movedCharge));
    storedCharge += movedCharge;
}

double Capacitor::getCurrent()
{
    return (capacitance * (getVoltage() - storedCharge));
}

Capacitor::~Capacitor()
{
}