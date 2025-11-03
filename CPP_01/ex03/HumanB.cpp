#include "HumanB.hpp"

HumanB::HumanB() : name_("Unnamed"), _weapon(NULL) {}

HumanB::HumanB(std::string n) : name_(n), _weapon(NULL) {}

HumanB::HumanB(const HumanB &other) : name_(other.name_) {}

HumanB &HumanB::operator=(const HumanB &other)
{
    if (this != &other)
    {
        name_ = other.name_;
        _weapon = other._weapon;
    }
    return *this;
}

HumanB::~HumanB() {}

void HumanB::attack(void)
{
    std::cout << name_ << " attacks with their " << (_weapon ? _weapon->getType() : "fists") << std::endl;
}

void HumanB::setWeapon(Weapon &w)
{
    _weapon = &w;
}