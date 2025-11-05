#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name)
    : ClapTrap(name)
{
    std::cout << "Constructor called for FragTrap " << name << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

FragTrap::FragTrap(const FragTrap &other)
    : ClapTrap(other)
{
    std::cout << "Copy constructor called for FragTrap " << name << "with FragTrap" << other.name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "Assignment operator called for FragTrap " << name << " with FragTrap " << other.name << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor called for FragTrap " << name << std::endl;
}

void FragTrap::attack(std::string const &target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        energyPoints--;
        std::cout << "FragTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= amount)
    {
        hitPoints = 0;
        std::cout << "FragTrap " << name << " has been destroyed!" << std::endl;
    }
    else
    {
        hitPoints -= amount;
        std::cout << "FragTrap " << name << " takes " << amount
                  << " points of damage! Remaining hit points: " << hitPoints << std::endl;
    }
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        energyPoints--;
        hitPoints += amount;
        std::cout << "FragTrap " << name << " is repaired by " << amount
                  << " points! Current hit points: " << hitPoints << std::endl;
    }
}


void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " says: High-fives, guys?" << std::endl;
}