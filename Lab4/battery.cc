#include "Battery.h"
#include "Component.h"
#include <iostream>
#include <string>

using namespace std;

Battery::Battery(string const name, double const voltage, Connection *const left, Connection *const right)
    : Component(name, left, right), voltage{voltage}
{
}

void Battery::update(double const timeStep)
{
    left->setVoltage(voltage);
    right->setVoltage(0);
}

// double Battery::getVoltage()
// {
//     return voltage;
// }

double Battery::getCurrent()
{
    return 0;
}

Battery::~Battery()
{
}