// Capacitor h file

#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "Component.h"

class Capacitor : public Component
{
public:
    Capacitor();
    double getCurrent() override;
    ~Capacitor();
private:
};

#endif
