#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
    std::string name_;
    Weapon *weapon_;

public:
    // Parameterized constructer
    HumanB(std::string n);

    // Destructor
    ~HumanB();

    void attack(void);

    void setWeapon(Weapon &w);
};

#endif