#include "HumanB.hpp"

HumanB::HumanB() : _name("Unnamed"), _weapon(NULL) {}

HumanB::HumanB(std::string n) : _name(n), _weapon(NULL) {}

HumanB::HumanB(const HumanB &other) : _name(other._name) {}

HumanB &HumanB::operator=(const HumanB &other)
{
    if (this != &other)
    {
        _name = other._name;
        _weapon = other._weapon;
    }
    return *this;
}

HumanB::~HumanB() {}

void HumanB::attack(void)
{
    std::cout << _name << " attacks with their " << (_weapon ? _weapon->getType() : "fists") << std::endl;
}

void HumanB::setWeapon(Weapon &w)
{
    _weapon = &w;
}