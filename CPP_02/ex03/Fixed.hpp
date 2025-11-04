#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int num_;
    static const int fraction_;

public:
    // Default constructor
    Fixed();

    // Parameterized constructer
    Fixed(const int num);   // from int
    Fixed(const float num); // from float

    // Copy constructor
    Fixed(const Fixed &other);

    // Copy assignment operator
    Fixed &operator=(const Fixed &other);

    // Destructor
    ~Fixed();

    float toFloat() const;
    int toInt() const;

    int getRawBits() const;
    void setRawBits(int const raw);

    // Comparison operators
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    //++ and --
    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    // min and max
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif
