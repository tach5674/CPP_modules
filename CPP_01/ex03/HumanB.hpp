#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
    std::string name_;
    Weapon *_weapon;

public:
    // Default constructor
    HumanB();

    // Parameterized constructer
    HumanB(std::string n);

    // Copy constructor
    HumanB(const HumanB &other);

    // Copy assignment operator
    HumanB &operator=(const HumanB &other);

    // Destructor
    ~HumanB();

    void attack(void);

    void setWeapon(Weapon &w);
};

#endif