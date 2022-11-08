
#include "Connection.h"

using namespace std;

Connection::Connection()
{
}

double Connection::setVoltage(double v)
{
    voltage = v;
}

double Connection::getVoltage()
{
    return voltage;
}

Connection::~Connection()
{
}