#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name)
    : ClapTrap(name)
{
    std::cout << "Constructor called for FragTrap " << name_ << std::endl;
    hitPoints_ = 100;
    energyPoints_ = 50;
    attackDamage_ = 20;
}

FragTrap::FragTrap(const FragTrap &other)
    : ClapTrap(other)
{
    std::cout << "Copy constructor called for FragTrap " << name_ << "with FragTrap" << other.name_ << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "Assignment operator called for FragTrap " << name_ << " with FragTrap " << other.name_ << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor called for FragTrap " << name_ << std::endl;
}

void FragTrap::attack(std::string const &target)
{
    if (energyPoints_ > 0 && hitPoints_ > 0)
    {
        energyPoints_--;
        std::cout << "FragTrap " << name_ << " attacks " << target
                  << ", causing " << attackDamage_ << " points of damage!" << std::endl;
    }
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (hitPoints_ <= amount)
    {
        hitPoints_ = 0;
        std::cout << "FragTrap " << name_ << " has been destroyed!" << std::endl;
    }
    else
    {
        hitPoints_ -= amount;
        std::cout << "FragTrap " << name_ << " takes " << amount
                  << " points of damage! Remaining hit points: " << hitPoints_ << std::endl;
    }
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (energyPoints_ > 0 && hitPoints_ > 0)
    {
        energyPoints_--;
        hitPoints_ += amount;
        std::cout << "FragTrap " << name_ << " is repaired by " << amount
                  << " points! Current hit points: " << hitPoints_ << std::endl;
    }
}


void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name_ << " says: High-fives, guys?" << std::endl;
}