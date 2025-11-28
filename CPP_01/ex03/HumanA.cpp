#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon &w) : name_(n), weapon_(w) {}

HumanA::~HumanA() {}

void HumanA::attack(void)
{
    std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}
