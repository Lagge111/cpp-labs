#ifndef COMPONENT_H
#define COMPONENT_H

#include "Connection.h"
#include <string>

// TODO: Complementary work needed: Use reference to constant for input parameters
// of class type.
/**
 * Fixed by using reference to constant for input parameters of class type.
*/

// TODO: Complemetary work needed: Functions not doing anything in the baseclass
// and are virtual shoukd be declared pure virtual
/**
 * Fixed by assigning pure virtual to update in Component.
 */

// TODO: Complementary work needed: Your destructor is empty, should therefore
// be set default in baseclass.
/**
 * Fixed by setting destructor to default in Component.
 */

// TODO: Complementary work needed: Your destructor should be virtual in
// base class, which affects the subclasses.
/**
 * Fixed by assigning virtual to destructor in Component.
 */

class Component
{
public:
    Component(std::string const& name, Connection *const left, Connection *const right);
    virtual void update(double const /* timeStep */) = 0;
    double getVoltage() const;
    virtual double getCurrent() const;
    std::string getName() const;
    void moveVoltage(Connection *lowest, Connection *highest, double movedCharge);
    virtual ~Component() = default;

protected:
    std::string name;
    Connection *left;
    Connection *right;
};

#endif