#include "Simulation.h"
#include <iostream>
#include <iomanip>

using namespace std;

Simulation::Simulation()
{
}

void Simulation::simulate(vector<Component *> const circuit, int const iterations, int const outputRows, double const timeStep)
{
    cout << fixed << setprecision(2) << endl
         << " ";

    /* Print the name of each component */
    for (Component *component : circuit)
    {
        cout << setw(12) << component->getName() << " ";
    }

    cout << endl
         << " ";

    /* Print the voltage and current header for each component */
    for (Component *component : circuit)
    {
        cout << setw(6) << "Volt";
        cout << setw(7) << "Curr ";
    }

    cout << endl;

    /* Print the voltage and current for each component, for each printed iteration */
    for (int i{1}; i <= iterations; ++i)
    {
        for (Component *component : circuit)
        {
            component->update(timeStep);
        }
        if (i % (iterations / outputRows) == 0)
        {
            for (Component *component : circuit)
            {
                cout << setw(7) << component->getVoltage();
                cout << setw(6) << component->getCurrent();
            }
            cout << endl;
        }
    }
}

Simulation::~Simulation()
{
}