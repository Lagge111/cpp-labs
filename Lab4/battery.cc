#include "Battery.h"
#include "Component.h"

using namespace std;

Battery::Battery(string const name, double const voltage, Connection *const left, Connection *const right)
    : Component(name, left, right), voltage{voltage}, current{current}
{
}

void Battery::update(double const /* timeStep */)
{
    left->setVoltage(voltage);
    right->setVoltage(0);
}

Battery::~Battery()
{
}