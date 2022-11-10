// Battery component

#include "Battery.h"
#include "Component.h"
#include <iostream>
#include <string>

using namespace std;

Battery::Battery(string const name, double const voltage, Connection *const left, Connection *const right)
    : Component(name, left, right), voltage{voltage}
{
    cout << "Battery created: " << getName() << endl;
    // setLeft();
}

void Battery::update(double const timeStep)
{
    // Do something
}

double Battery::getVoltage()
{
    return voltage;
}

double Battery::getCurrent()
{
    return 0;
}

Battery::~Battery()
{
}