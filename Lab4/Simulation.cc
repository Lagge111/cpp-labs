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
    cout << "Simulation/simulate" << endl;
    int size{static_cast<int>(net.size())};
    for (int i{0}; i < size; ++i)
    {
        cout << setw(12) << net.at(i)->getName();
        // cout << "Simulation/simulate/loop" << endl;
        // cout << "Component name: " << net.at(i)->name << endl;
    }
    cout << endl;
    cout << left;
    cout << setw(5) << "";
    for (int i{0}; i < size; ++i) {
        cout << "Volt   Curr ";
    }

    cout << endl;

    for (int i{1}; i <= iterations; ++i) {
        for (Component* c : net) {
            // This will work once update is implemented
            // c->update(timeStep);
        }
        if ((i % iterations / outputRows) == 0) {
            cout << fixed << setprecision(2) << setw(6) << "";

            for (Component* c : net) {
                cout << setw(6) << "3.00" << "4.30" << "  ";
                // This will work once getVoltage and getCurrent are implemented
                // cout << setw(6) << c->getVoltage() << c->getCurrent() << "  ";
            }
            cout << endl;
        }
    }
}

Simulation::~Simulation()
{
}