#ifndef SIMULATION_H
#define SIMULATION_H

#include "Component.h"
#include <vector>

class Simulation
{
public:
    Simulation();
    void simulate(std::vector<Component *> const circuit, int const iterations, int const outputRows, double const timeStep);
    ~Simulation();

private:
};

#endif