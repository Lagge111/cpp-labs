#include "Component.h"
#include "Connection.h"

using namespace std;

Component::Component(string const name, Connection *const left, Connection *const right) : name{name}, left{left}, right{right}
{
}

void Component::update(double const timeStep)
{
}

double Component::getVoltage()
{
    return abs(left->getVoltage() - right->getVoltage());
}

double Component::getCurrent()
{
    return 0;
}

string Component::getName()
{
    return name;
}

void Component::changeVoltage(Connection *lowest, Connection *highest, double movedCharge)
{
    lowest->setVoltage(lowest->getVoltage() + movedCharge);
    highest->setVoltage(highest->getVoltage() - movedCharge);
}

Component::~Component()
{
}