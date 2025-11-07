#include "Animal.hpp"

Animal::Animal() : type_("Animal")
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type_(other.type_)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other)
        this->type_ = other.type_;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return type_;
}
