#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat constructor called" << std::endl;
    type_ = "Cat";
    brain_ = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    brain_ = new Brain(*other.brain_);
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain_;
        brain_ = new Brain(*other.brain_);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete brain_;
}

void Cat::makeSound() const
{
    std::cout << "Meow~" << std::endl;
}
