#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
    std::string type_;

public:
    // Default constructor
    Weapon();

    // Parameterized constructer
    Weapon(std::string n);

    // Copy constructor
    Weapon(const Weapon &other);

    // Copy assignment operator
    Weapon &operator=(const Weapon &other);

    // Destructor
    ~Weapon();

    const std::string &getType(void);

    void setType(std::string type);
};

#endif