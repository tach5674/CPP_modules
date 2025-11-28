#include "HumanB.hpp"

HumanB::HumanB() : name_("Unnamed"), weapon_(NULL) {}

HumanB::HumanB(std::string n) : name_(n), weapon_(NULL) {}

HumanB::HumanB(const HumanB &other) : name_(other.name_) {}

HumanB &HumanB::operator=(const HumanB &other)
{
    if (this != &other)
    {
        name_ = other.name_;
        weapon_ = other.weapon_;
    }
    return *this;
}

HumanB::~HumanB() {}

void HumanB::attack(void)
{
    std::cout << name_ << " attacks with their " << (weapon_ ? weapon_->getType() : "fists") << std::endl;
}

void HumanB::setWeapon(Weapon &w)
{
    weapon_ = &w;
}