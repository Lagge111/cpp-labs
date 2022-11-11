
#include "Capacitor.h"
#include "Component.h"

using namespace std;

Capacitor::Capacitor(string const name, double const capacitance, Connection* const left, Connection* const right) 
: Component(name, left, right), capacitance{capacitance}, storedVoltage{storedVoltage}
{
}

void Capacitor::update(double const timeStep)
{
    //double voltageMoved{(getVoltage() / resistance) * timeStep};

    if (left->getVoltage() < right->getVoltage()) {
        storedVoltage = (capacitance * (right->getVoltage() - left->getVoltage()) * timeStep);

        // left->setVoltage(left->getVoltage() + voltageMoved);
        // right->setVoltage(right->getVoltage() - voltageMoved);

    } else {
        storedVoltage = (capacitance * (left->getVoltage() - right->getVoltage()) * timeStep);

        // right->setVoltage(right->getVoltage() + voltageMoved);
        // left->setVoltage(left->getVoltage() - voltageMoved);
    }
}

double Capacitor::getCurrent()
{
    return 0;
}


Capacitor::~Capacitor()
{
}