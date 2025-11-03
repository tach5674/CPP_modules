#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int num_;
    static const int fraction_ = 8; // 8 fractional bits

public:
    // Default constructor
    Fixed();

    // Copy constructor
    Fixed(const Fixed &other);

    // Copy assignment operator
    Fixed &operator=(const Fixed &other);

    // Destructor
    ~Fixed();

    int getRawBits() const;
    void setRawBits(int const raw);
};

#endif
