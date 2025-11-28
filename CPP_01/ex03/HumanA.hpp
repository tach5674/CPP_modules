#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
    std::string name_;
    Weapon *weapon_;

public:
    // Default constructor
    HumanA();

    // Parameterized constructer
    HumanA(std::string n, Weapon &w);

    // Copy constructor
    HumanA(const HumanA &other);

    // Copy assignment operator
    HumanA &operator=(const HumanA &other);

    // Destructor
    ~HumanA();

    void attack(void);
};

#endif