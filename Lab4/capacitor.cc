// Capacitor component

#include "Capacitor.h"
#include "Component.h"

using namespace std;

Capacitor::Capacitor() : Component(name, left, right)
{
}

double Capacitor::getCurrent()
{
    return 0;
}

Capacitor::~Capacitor()
{
}