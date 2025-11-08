#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
protected:
    std::string name_;
    unsigned int hitPoints_;
    unsigned int energyPoints_;
    unsigned int attackDamage_;

public:
    ClapTrap();
    ClapTrap(const std::string &name = "Unnamed");
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &other);
    ~ClapTrap();

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif