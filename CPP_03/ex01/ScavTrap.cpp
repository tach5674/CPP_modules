#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name)
    : ClapTrap(name)
{
    std::cout << "Constructor called for ScavTrap " << name << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other)
    : ClapTrap(other)
{
    std::cout << "Copy constructor called for ScavTrap " << name << "with ScavTrap" << other.name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "Assignment operator called for ScavTrap " << name << " with ScavTrap " << other.name << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor called for ScavTrap " << name << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        energyPoints--;
        std::cout << "ScavTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= amount)
    {
        hitPoints = 0;
        std::cout << "ScavTrap " << name << " has been destroyed!" << std::endl;
    }
    else
    {
        hitPoints -= amount;
        std::cout << "ScavTrap " << name << " takes " << amount
                  << " points of damage! Remaining hit points: " << hitPoints << std::endl;
    }
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        energyPoints--;
        hitPoints += amount;
        std::cout << "ScavTrap " << name << " is repaired by " << amount
                  << " points! Current hit points: " << hitPoints << std::endl;
    }
}


void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gatekeeper mode" << std::endl;
}