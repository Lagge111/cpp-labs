#include "Component.h"
#include "Connection.h"
#include <string>

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

Component::~Component()
{
}