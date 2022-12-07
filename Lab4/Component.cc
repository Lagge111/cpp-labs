#include "Component.h"
#include "Connection.h"

using namespace std;

Component::Component(string const& name, Connection *const left, Connection *const right) : name{name}, left{left}, right{right}
{
}

void Component::update(double const /* timeStep */)
{
}

double Component::getVoltage() const
{
    return abs(left->getVoltage() - right->getVoltage());
}

double Component::getCurrent() const
{
    return 0;
}

string Component::getName() const
{
    return name;
}

void Component::moveVoltage(Connection *lowest, Connection *highest, double movedCharge)
{
    lowest->setVoltage(lowest->getVoltage() + movedCharge);
    highest->setVoltage(highest->getVoltage() - movedCharge);
}