#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    (void)other;
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}