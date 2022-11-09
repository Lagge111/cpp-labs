// Component

#include "Component.h"
#include "Connection.h"
#include <string>

using namespace std;

Component::Component(string const name, Connection *const left, Connection *const right) : name{name}, left{left}, right{right}
{
}

Component::~Component()
{
}