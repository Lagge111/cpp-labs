#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include "Component.h"

class Simulation
{
public:
    void simulate(std::vector<Component *> const net, int const iterations, int const outputRows, double const timeStep);

private:
};

#endif