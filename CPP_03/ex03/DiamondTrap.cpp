#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("Unnamed_clap_name"),
      FragTrap("Unnamed"),
      ScavTrap("Unnamed"),
      name_("Unnamed")
{
    std::cout << "Default constructor called for DiamondTrap " << name_ << std::endl;

    hitPoints_ = FragTrap::hitPoints_;
    energyPoints_ = ScavTrap::energyPoints_;
    attackDamage_ = FragTrap::attackDamage_;
}
DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"),
      FragTrap(name),
      ScavTrap(name),
      name_(name)
{
    std::cout << "Parameterized constructor called for DiamondTrap " << name_ << std::endl;

    hitPoints_ = FragTrap::hitPoints_;
    energyPoints_ = ScavTrap::energyPoints_;
    attackDamage_ = FragTrap::attackDamage_;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other),
      FragTrap(other),
      ScavTrap(other)
{
    std::cout << "Copy constructor called for DiamondTrap " << name_ << "with DiamondTrap " << other.name_ << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "Assignment operator called for DiamondTrap " << name_ << " with DiamondTrap " << other.name_ << std::endl;

    if (this != &other)
    {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        name_ = other.name_;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {}

void DiamondTrap::attack(std::string const &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
    if (hitPoints_ <= amount)
    {
        hitPoints_ = 0;
        std::cout << "DiamondTrap " << name_ << " has been destroyed!" << std::endl;
    }
    else
    {
        hitPoints_ -= amount;
        std::cout << "DiamondTrap " << name_ << " takes " << amount
                  << " points of damage! Remaining hit points: " << hitPoints_ << std::endl;
    }
}

void DiamondTrap::beRepaired(unsigned int amount)
{
    if (energyPoints_ > 0 && hitPoints_ > 0)
    {
        energyPoints_--;
        hitPoints_ += amount;
        std::cout << "DiamondTrap " << name_ << " is repaired by " << amount
                  << " points! Current hit points: " << hitPoints_ << std::endl;
    }
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name is " << name_ << " and ClapTrap name is " << ClapTrap::name_ << std::endl;
}