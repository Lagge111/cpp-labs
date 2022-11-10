// Main class which creates the circuits.

#include <iostream>
#include <string>

#include "Connection.h"
#include "Component.h"
#include "Battery.h"
#include "Resistor.h"
#include "Simulation.h"

using namespace std;

// Declaring the methods so that they can be used in the main method.
void circuit_1(int const iterations, int const outputRows, double const timeStep, double const voltage);
void circuit_2();
void circuit_3();
void deallocate_components(std::vector<Component *> v);

// Main method
int main(int argc, char **argv)
{
    cout << "Main" << endl;
    if (argc == 5) {
        try {
            // Declared variables locally as it didn't fucking work otherwise
            int iterations{stoi(argv[1])};
            int outputRows{stoi(argv[2])};
            double timeStep{stod(argv[3])};
            double voltage{stod(argv[4])};

            circuit_1(iterations, outputRows, timeStep, voltage);

        } catch (invalid_argument& e) {
            cout << "Invalid type of arguments. Should be int int double double." << endl;
        }
    } else {
        cout << "Invalid number of arguments." << endl;
        return 1;
    }
}

// Method for creating circuit 1 from the example.
void circuit_1(int const iterations, int const outputRows, double const timeStep, double const voltage)
{
    cout << "Circuit_1 - 1" << endl;
    Connection p, n, r124, r23;
    vector<Component *> net;
    cout << "Circuit_1 - 2" << endl;
    net.push_back(new Battery("Bat", voltage, &p, &n));
    net.push_back(new Resistor("R1", 6, &p, &r124));
    net.push_back(new Resistor("R2", 4, &r124, &r23));
    net.push_back(new Resistor("R3", 8, &r23, &n));
    net.push_back(new Resistor("R4", 12, &r124, &n));
    cout << "Circuit_1 - 3" << endl;
    Simulation simulation{};
    cout << "Circuit_1 - 4" << endl;
    simulation.simulate(net, iterations, outputRows, timeStep);
    deallocate_components(net);
}

// Method for creating circuit 2 from the example.
void circuit_2()
{
}

// Method for creating circuit 3 from the example.
void circuit_3()
{
}

void deallocate_components(std::vector<Component *> v)
{
    for (Component *elements : v)
    {
        cout << "Deleting element: " << elements << endl;
        delete elements;
    }
    // Pre-defined function for vectors 
    v.clear();
}
