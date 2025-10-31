#include "HumanA.hpp"

HumanA::HumanA() : _name("Unnamed"), _weapon(NULL) {}

HumanA::HumanA(std::string n, Weapon &w) : _name(n), _weapon(&w) {}

HumanA::HumanA(const HumanA &other) : _name(other._name), _weapon(other._weapon) {}

HumanA &HumanA::operator=(const HumanA &other)
{
    if (this != &other)
    {
        _name = other._name;
        _weapon = other._weapon;
    }
    return *this;
}

HumanA::~HumanA() {}

void HumanA::attack(void)
{
    std::cout << _name << " attacks with their " << (_weapon ? _weapon->getType() : "fists") << std::endl;
}
