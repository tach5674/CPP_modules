#include "Fixed.hpp"

const int Fixed::fraction_ = 8;

Fixed::Fixed() : num_(0)
{
    // std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int num) : num_(num << fraction_)
{
    // std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float num) : num_(roundf(num * (1 << fraction_)))
{
    // std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
    // std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    // std::cout << "Copy assignment operator called\n";
    if (this != &other)
        num_ = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called\n";
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
    // std::cout << "getRawBits member function called\n";
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

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.num_ = (this->num_ + other.num_);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.num_ = (this->num_ - other.num_);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.num_ = (long long)this->num_ * other.num_ >> fraction_;
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result.num_ = (((long long)this->num_ << fraction_) / other.num_);
    return result;
}

Fixed &Fixed::operator++()
{
    num_++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed old = *this;
    operator++();
    return old;
}

Fixed &Fixed::operator--()
{
    num_--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed old = *this;
    operator--();
    return old;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->num_ == other.num_;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->num_ != other.num_;
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->num_ < other.num_;
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->num_ > other.num_;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->num_ <= other.num_;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->num_ >= other.num_;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}