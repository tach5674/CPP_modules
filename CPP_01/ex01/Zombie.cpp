#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string n) : _name(n) {}

Zombie::Zombie(const Zombie &other) : _name(other._name) {}

Zombie &Zombie::operator=(const Zombie &other)
{
    if (this != &other)
        _name = other._name;
    return *this;
}

Zombie::~Zombie() {};

void Zombie::announce()
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
    this->_name = name;
}