#include "Weapon.hpp"

Weapon::Weapon() : _type("fists") {}

Weapon::Weapon(std::string t) : _type(t) {}

Weapon::Weapon(const Weapon &other) : _type(other._type) {}

Weapon &Weapon::operator=(const Weapon &other)
{
    if (this != &other)
        _type = other._type;
    return *this;
}

Weapon::~Weapon() {}

const std::string &Weapon::getType(void)
{
    return _type;
}

void Weapon::setType(std::string t)
{
    _type = t;
}
