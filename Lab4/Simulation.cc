#include <iostream>
#include <string>
#include <iomanip>

#include "Simulation.h"

using namespace std;

Simulation::Simulation()
{
}

void Simulation::simulate(vector<Component *> const net, int const iterations, int const outputRows, double const timeStep)
{
    cout << "Executing simulation: " << endl;
    int size{static_cast<int>(net.size())};
    for (int i{0}; i < size; ++i)
    {
        cout << setw(10) << net.at(i)->getName();
    }
    cout << endl;
    cout << left;
    cout << setw(0) << "";
    for (int i{0}; i < size; ++i) {
        cout << "Volt  Curr  ";
    }

    cout << endl;

    for (int i{1}; i <= iterations; ++i) {
        for (Component* c : net) {
            c->update(timeStep);
        }
        if ((i % (iterations / outputRows)) == 0) {
            cout << fixed << setprecision(2) << setw(0) << "";
            for (Component* c : net) {
                cout << setw(6) << c->getVoltage() << c->getCurrent() << "  ";
            }
            cout << endl;
        }
    }
}

Simulation::~Simulation()
{
}