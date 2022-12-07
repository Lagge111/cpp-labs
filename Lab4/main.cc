#include "Connection.h"
#include "Component.h"
#include "Battery.h"
#include "Resistor.h"
#include "Capacitor.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

// TODO: Complementary work needed: try/catch should only surround the
// functions which can throw the exceptions (stod, stoi). If the inputted
// parameters are correct, the program should run without failure.
/**
 * Fixed by calling the circuit functions outside of the try/catch.
 */

// TODO: Complementary work needed: You never catch your error in your catch
// block
/**
 * Fixed by catching the error.
 */

// TODO: Complementary work needed: Compiling your code with the
// "-Wall -Wextra -Wpedantic" flags should result in 0 warnings.
/**
 * Fixed by resolving the warnings.
 */

/**
 * Originally in the Simulation class:
 *      COMMENT: There's no need for a simulation class with only one function,
 *               could just as well be a function in main class.
 * Fixed by removing the Simulation class and by moving the simulation function to main.
 */

void circuit_1(int const iterations, int const outputRows, double const timeStep, double const voltage);
void circuit_2(int const iterations, int const outputRows, double const timeStep, double const voltage);
void circuit_3(int const iterations, int const outputRows, double const timeStep, double const voltage);
void simulate(vector<Component *> const circuit, int const iterations, int const outputRows, double const timeStep);
void deallocate_components(vector<Component *> v);

int iterations{};
int outputRows{};
double timeStep{};
double voltage{};

int main(int argc, char **argv)
{
    if (argc == 5)
    {
        try
        {
            iterations = stoi(argv[1]);
            outputRows = stoi(argv[2]);
            timeStep = stod(argv[3]);
            voltage = stod(argv[4]);
        }
        catch (invalid_argument &e)
        {
            cerr << "Invalid argument(s). Arguments should follow the format 'int' (iterations) 'int' (printed lines) 'double' (time step) 'double' (voltage)."
                 << "\nError occurred in operation: " << e.what() << endl;
            return 1;
        }
        catch (out_of_range &e)
        {
            cerr << "Value out of range for operation: " << e.what() << endl;
            return 1;
        }
    }
    else
    {
        cout << "Invalid number of arguments. Please include four (4) arguments." << endl;
        return 1;
    }
    circuit_1(iterations, outputRows, timeStep, voltage);
    circuit_2(iterations, outputRows, timeStep, voltage);
    circuit_3(iterations, outputRows, timeStep, voltage);
}

void circuit_1(int const iterations, int const outputRows, double const timeStep, double const voltage)
{
    Connection p, n, r124, r23;
    vector<Component *> circuit;
    circuit.push_back(new Battery("Bat", voltage, &p, &n));
    circuit.push_back(new Resistor("R1", 6, &p, &r124));
    circuit.push_back(new Resistor("R2", 4, &r124, &r23));
    circuit.push_back(new Resistor("R3", 8, &r23, &n));
    circuit.push_back(new Resistor("R4", 12, &r124, &n));
    simulate(circuit, iterations, outputRows, timeStep);
    deallocate_components(circuit);
}

void circuit_2(int const iterations, int const outputRows, double const timeStep, double const voltage)
{
    Connection p, n, l, r;
    vector<Component *> circuit;
    circuit.push_back(new Battery("Bat", voltage, &p, &n));
    circuit.push_back(new Resistor("R1", 150, &p, &l));
    circuit.push_back(new Resistor("R2", 50, &p, &r));
    circuit.push_back(new Resistor("R3", 100, &l, &r));
    circuit.push_back(new Resistor("R4", 300, &l, &n));
    circuit.push_back(new Resistor("R5", 250, &r, &n));
    simulate(circuit, iterations, outputRows, timeStep);
    deallocate_components(circuit);
}

void circuit_3(int const iterations, int const outputRows, double const timeStep, double const voltage)
{
    Connection p, n, l, r;
    vector<Component *> circuit;
    circuit.push_back(new Battery("Bat", voltage, &p, &n));
    circuit.push_back(new Resistor("R1", 150, &p, &l));
    circuit.push_back(new Resistor("R2", 50, &p, &r));
    circuit.push_back(new Capacitor("C3", 1.0, &l, &r));
    circuit.push_back(new Resistor("R4", 300, &l, &n));
    circuit.push_back(new Capacitor("C5", 0.75, &r, &n));
    simulate(circuit, iterations, outputRows, timeStep);
    deallocate_components(circuit);
}

void simulate(vector<Component *> const circuit, int const iterations, int const outputRows, double const timeStep)
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

    /* Print the voltage and current headers for each component */
    int curcuit_size{static_cast<int>(circuit.size())};

    for (int i{0}; i < curcuit_size; ++i)
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

void deallocate_components(vector<Component *> circuit)
{
    for (Component *component : circuit)
    {
        delete component;
    }
    circuit.clear();
}