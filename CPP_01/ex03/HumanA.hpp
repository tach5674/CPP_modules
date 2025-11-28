#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
    std::string name_;
    Weapon &weapon_;

public:
    // Parameterized constructer
    HumanA(std::string n, Weapon &w);

    // Destructor
    ~HumanA();

    void attack(void);
};

#endif