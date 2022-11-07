// Battery component

#include "Battery.h"
#include "Component.h"

using namespace std;

Battery::Battery(string const _name, double const _voltage, Connection* const _left, Connection* const _right) : Component, voltage{_voltage}
{
    setLeft();
}

double getVoltage()
{
    return voltage;
}

void setLeft()
{
    left->setVoltage(voltage);
}

~Battery()
{

}