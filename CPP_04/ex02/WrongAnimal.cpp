#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("WrongAnimal")
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type_(other.type_)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &other)
        this->type_ = other.type_;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type_;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sounds~" << std::endl;
}
