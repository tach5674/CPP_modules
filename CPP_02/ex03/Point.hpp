#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    Fixed x;
    Fixed y;

public:
    Point();
    Point(const float x_val, const float y_val);
    Point(const Point &other);
    Point &operator=(const Point &other);
    ~Point();

    Fixed getX() const;
    Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif