#include "Connection.h"

Connection::Connection() : voltage{0}
{
}

void Connection::setVoltage(double const v)
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
