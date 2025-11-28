#include "HumanB.hpp"

HumanB::HumanB(std::string n) : name_(n), weapon_(NULL) {}

HumanB::~HumanB() {}

void HumanB::attack(void)
{
    std::cout << name_ << " attacks with their " << (weapon_ ? weapon_->getType() : "fists") << std::endl;
}

void HumanB::setWeapon(Weapon &w)
{
    weapon_ = &w;
}