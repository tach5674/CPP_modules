#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap("Unnamed")
{
    std::cout << "Default constructor called for ScavTrap " << name_ << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
    : ClapTrap(name)
{
    std::cout << "Parameterized constructor called for ScavTrap " << name_ << std::endl;
    hitPoints_ = 100;
    energyPoints_ = 50;
    attackDamage_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other)
    : ClapTrap(other)
{
    std::cout << "Copy constructor called for ScavTrap " << name_ << "with ScavTrap " << other.name_ << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "Assignment operator called for ScavTrap " << name_ << " with ScavTrap " << other.name_ << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor called for ScavTrap " << name_ << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
    if (energyPoints_ > 0 && hitPoints_ > 0)
    {
        energyPoints_--;
        std::cout << "ScavTrap " << name_ << " attacks " << target
                  << ", causing " << attackDamage_ << " points of damage!" << std::endl;
    }
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (hitPoints_ <= amount)
    {
        hitPoints_ = 0;
        std::cout << "ScavTrap " << name_ << " has been destroyed!" << std::endl;
    }
    else
    {
        hitPoints_ -= amount;
        std::cout << "ScavTrap " << name_ << " takes " << amount
                  << " points of damage! Remaining hit points: " << hitPoints_ << std::endl;
    }
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (energyPoints_ > 0 && hitPoints_ > 0)
    {
        energyPoints_--;
        hitPoints_ += amount;
        std::cout << "ScavTrap " << name_ << " is repaired by " << amount
                  << " points! Current hit points: " << hitPoints_ << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name_ << " is now in Gatekeeper mode" << std::endl;
}