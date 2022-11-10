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
void deallocate_components(vector<Component *> v);

// Main method
int main(int argc, char **argv)
{
    cout << "Start of main" << endl;
    if (argc == 5) {
        try {
            // Declared variables locally as it didn't fucking work otherwise
            int iterations{stoi(argv[1])};
            int outputRows{stoi(argv[2])};
            double timeStep{stod(argv[3])};
            double voltage{stod(argv[4])};

            circuit_1(iterations, outputRows, timeStep, voltage);

        // Pre-defined exception for command line arguments
        } catch (invalid_argument& e) {
            cout << "Invalid argument type. Arguments should follow the format 'int int double double'." << endl;
        }
    } else {
        cout << "Invalid number of arguments." << endl;
        return 1;
    }
}

// Method for creating circuit 1 from the example.
void circuit_1(int const iterations, int const outputRows, double const timeStep, double const voltage)
{
    Connection p, n, r124, r23;
    cout << "Connections created" << endl;
    vector<Component *> net;
    cout << "Vector created" << endl;
    cout << "Creating components: " << endl;
    net.push_back(new Battery("Bat", voltage, &p, &n));
    net.push_back(new Resistor("R1", 6, &p, &r124));
    net.push_back(new Resistor("R2", 4, &r124, &r23));
    net.push_back(new Resistor("R3", 8, &r23, &n));
    net.push_back(new Resistor("R4", 12, &r124, &n));
    cout << "Components created" << endl;
    Simulation simulation{};
    cout << "Simulation instantiated" << endl;
    simulation.simulate(net, iterations, outputRows, timeStep);
    cout << "Simulation complete" << endl;
    deallocate_components(net);
    cout << "Vector deallocated" << endl;
}

// Method for creating circuit 2 from the example.
void circuit_2()
{
}

// Method for creating circuit 3 from the example.
void circuit_3()
{
}

void deallocate_components(std::vector<Component *> net)
{
    cout << "Deallocating vector: " << endl;
    for (Component *element : net)
    {
        cout << "Deleting element: " << element << endl;
        delete element;
    }
    // Pre-defined function for vectors 
    net.clear();
}
