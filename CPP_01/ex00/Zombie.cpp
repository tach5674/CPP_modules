#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string n) : name_(n) {}

Zombie::Zombie(const Zombie &other) : name_(other.name_) {}

Zombie &Zombie::operator=(const Zombie &other)
{
    if (this != &other)
        name_ = other.name_;
    return *this;
}

Zombie::~Zombie()
{
    std::cout << "Destructor called for " << name_ << std::endl;
};

void Zombie::announce()
{
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}