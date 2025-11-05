#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const &name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "Constructor called for ClapTrap " << name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
    : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
    std::cout << "Copy constructor called for ClapTrap " << name << "with ClapTrap" << other.name << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
    std::cout << "Assignment operator called for ClapTrap " << name << " with ClapTrap " << other.name << std::endl;
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called for ClapTrap " << name << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        energyPoints--;
        std::cout << "ClapTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= amount)
    {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
    }
    else
    {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount
                  << " points of damage! Remaining hit points: " << hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        energyPoints--;
        hitPoints += amount;
        std::cout << "ClapTrap " << name << " is repaired by " << amount
                  << " points! Current hit points: " << hitPoints << std::endl;
    }
}
