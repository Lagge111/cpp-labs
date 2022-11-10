#include "Connection.h"

Connection::Connection()
{
}

void Connection::setVoltage(double v)
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