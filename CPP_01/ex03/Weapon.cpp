#include "Weapon.hpp"

Weapon::Weapon() : type_("fists") {}

Weapon::Weapon(std::string t) : type_(t) {}

Weapon::Weapon(const Weapon &other) : type_(other.type_) {}

Weapon &Weapon::operator=(const Weapon &other)
{
    if (this != &other)
        type_ = other.type_;
    return *this;
}

Weapon::~Weapon() {}

const std::string &Weapon::getType(void)
{
    return type_;
}

void Weapon::setType(std::string t)
{
    type_ = t;
}
