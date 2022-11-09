// Component h file

// Weird fucking error with #ifndef COMPONENT_H.
// The error doesn't show up in the terminal when running the code,
// it's just there
#ifndef COMPONENT_H
#define COMPONENT_H

#include "Connection.h"
#include <iostream>
#include <string>

using namespace std;

class Component
{
public:
    Component(string const name, Connection *const left, Connection *const right);
    ~Component();
    string name;

protected:
    Connection *left;
    Connection *right;
};

#endif