#include "Zombie.h"

Zombie::Zombie() {}

Zombie::Zombie(std::string n) : name(n) {}

Zombie::Zombie(const Zombie &other) : name(other.name) {}

Zombie &Zombie::operator=(const Zombie &other)
{
    if (this != &other)
        name = other.name;
    return *this;
}

Zombie::~Zombie() {};

void Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}