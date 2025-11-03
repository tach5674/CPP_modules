#include "Fixed.hpp"

Fixed::Fixed() : num_(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int num) : num_(num << fraction_)
{
    std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float num) : num_(roundf(num * (1 << fraction_)))
{
    std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        num_ = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

float Fixed::toFloat() const
{
    return (float)num_ / (1 << fraction_);
}

int Fixed::toInt() const
{
    return num_ >> fraction_;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called\n";
    return num_;
}

void Fixed::setRawBits(int const raw)
{
    num_ = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
    out << f.toFloat();
    return out;
}
