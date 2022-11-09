#include "Connection.h"

using namespace std;

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