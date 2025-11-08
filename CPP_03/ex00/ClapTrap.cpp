#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name_("Unnamed"), hitPoints_(10), energyPoints_(10), attackDamage_(0)
{
    std::cout << "Default constructor called for ClapTrap " << name_ << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
    : name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0)
{
    std::cout << "Parameterized constructor called for ClapTrap " << name_ << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : name_(other.name_), hitPoints_(other.hitPoints_), energyPoints_(other.energyPoints_), attackDamage_(other.attackDamage_)
{
    std::cout << "Copy constructor called for ClapTrap " << name_ << "with ClapTrap " << other.name_ << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Assignment operator called for ClapTrap " << name_ << " with ClapTrap " << other.name_ << std::endl;
    if (this != &other)
    {
        name_ = other.name_;
        hitPoints_ = other.hitPoints_;
        energyPoints_ = other.energyPoints_;
        attackDamage_ = other.attackDamage_;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called for ClapTrap " << name_ << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (energyPoints_ > 0 && hitPoints_ > 0)
    {
        energyPoints_--;
        std::cout << "ClapTrap " << name_ << " attacks " << target
                  << ", causing " << attackDamage_ << " points of damage!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints_ <= amount)
    {
        hitPoints_ = 0;
        std::cout << "ClapTrap " << name_ << " has been destroyed!" << std::endl;
    }
    else
    {
        hitPoints_ -= amount;
        std::cout << "ClapTrap " << name_ << " takes " << amount
                  << " points of damage! Remaining hit points: " << hitPoints_ << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints_ > 0 && hitPoints_ > 0)
    {
        energyPoints_--;
        hitPoints_ += amount;
        std::cout << "ClapTrap " << name_ << " is repaired by " << amount
                  << " points! Current hit points: " << hitPoints_ << std::endl;
    }
}
