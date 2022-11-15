
#include <iostream>
#include <iomanip>
#include "Simulation.h"

using namespace std;

Simulation::Simulation()
{
}

void Simulation::simulate(vector<Component *> const net, int const iterations, int const outputRows, double const timeStep)
{
    int size{static_cast<int>(net.size())};
    cout << endl;
    cout << " ";

    for (Component *element : net)
    {
        cout << setw(12) << element->getName() << " ";
    }

    cout << endl;
    cout << " ";

    for (int i{0}; i < size; ++i)
    {
        cout << setw(6) << "Volt";
        cout << setw(7) << "Curr ";
    }

    cout << endl;

    for (int i{1}; i <= iterations; i++)
    {
        for (Component *c : net)
        {
            c->update(timeStep);
        }
        if (i % (iterations / outputRows) == 0)
        {
            cout << fixed << setprecision(2);
            for (Component *c : net)
            {
                cout << setw(7) << c->getVoltage();
                cout << setw(6) << c->getCurrent();
            }
            cout << endl;
        }
    }
}

Simulation::~Simulation()
{
}