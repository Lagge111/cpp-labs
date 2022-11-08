
#include "Component.h"
#include "Connection.h"
#include <string>

using namespace std;

Component::Component(string const _name, Connection *const _left, Connection *const _right)
{
}

string Component::getName()
{
    // name is not declared. Should probably be included in the constructor
    return name;
}

Component::~Component()
{
}