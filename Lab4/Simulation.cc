#include <iostream>
#include <string>

#include "Simulation.h"

using namespace std;

void Simulation::simulate(vector<Component *> const net, int const iterations, int const outputRows, double const timeStep)
{
    cout << "Simulation/simulate" << endl;
    int size{static_cast<int>(net.size())};
    for (int i{1}; i < size; ++i)
    {
        cout << "Simulation/simulate/loop" << endl;
        cout << "Component name: " << net.at(i)->name << endl;
    }
}