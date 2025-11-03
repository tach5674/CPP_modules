#include "HumanA.hpp"

HumanA::HumanA() : name_("Unnamed"), _weapon(NULL) {}

HumanA::HumanA(std::string n, Weapon &w) : name_(n), _weapon(&w) {}

HumanA::HumanA(const HumanA &other) : name_(other.name_), _weapon(other._weapon) {}

HumanA &HumanA::operator=(const HumanA &other)
{
    if (this != &other)
    {
        name_ = other.name_;
        _weapon = other._weapon;
    }
    return *this;
}

HumanA::~HumanA() {}

void HumanA::attack(void)
{
    std::cout << name_ << " attacks with their " << (_weapon ? _weapon->getType() : "fists") << std::endl;
}
