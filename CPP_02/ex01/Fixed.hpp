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
    
    // Parameterized constructer
    Fixed(const int num);   // from int
    Fixed(const float num); // from float

    // opy constructor
    Fixed(const Fixed &other);

    // Copy assignment operator
    Fixed &operator=(const Fixed &other);

    // Destructor
    ~Fixed();

    float toFloat() const;
    int toInt() const;

    int getRawBits() const;
    void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif
