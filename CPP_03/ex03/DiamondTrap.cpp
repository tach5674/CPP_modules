#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"),
      FragTrap(name),
      ScavTrap(name)
{
    this->name_ = name;
    this->hitPoints_ = FragTrap::hitPoints_;
    this->energyPoints_ = ScavTrap::energyPoints_;
    this->attackDamage_ = FragTrap::attackDamage_;

    std::cout << "DiamondTrap constructor called for " << this->name_ << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other),
      FragTrap(other),
      ScavTrap(other)
{
    this->name_ = other.name_;

    std::cout << "DiamondTrap copy constructor called for " << this->name_ << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);

        this->name_ = other.name_;
    }

    std::cout << "DiamondTrap assignment operator called for " << this->name_ << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap(){}

void DiamondTrap::attack(std::string const &target)
{
    if (energyPoints_ > 0 && hitPoints_ > 0)
    {
        energyPoints_--;
        std::cout << "DiamondTrap " << name_ << " attacks " << target
                  << ", causing " << attackDamage_ << " points of damage!" << std::endl;
    }
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