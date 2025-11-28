#include "HumanA.hpp"

HumanA::HumanA() : name_("Unnamed"), weapon_(NULL) {}

HumanA::HumanA(std::string n, Weapon &w) : name_(n), weapon_(&w) {}

HumanA::HumanA(const HumanA &other) : name_(other.name_), weapon_(other.weapon_) {}

HumanA &HumanA::operator=(const HumanA &other)
{
    if (this != &other)
    {
        name_ = other.name_;
        weapon_ = other.weapon_;
    }
    return *this;
}

HumanA::~HumanA() {}

void HumanA::attack(void)
{
    std::cout << name_ << " attacks with their " << (weapon_ ? weapon_->getType() : "fists") << std::endl;
}
