#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1 = (b.getX() - a.getX()) * (point.getY() - a.getY()) -
               (b.getY() - a.getY()) * (point.getX() - a.getX());
               
    Fixed d2 = (c.getX() - b.getX()) * (point.getY() - b.getY()) -
               (c.getY() - b.getY()) * (point.getX() - b.getX());

    Fixed d3 = (a.getX() - c.getX()) * (point.getY() - c.getY()) -
               (a.getY() - c.getY()) * (point.getX() - c.getX());

    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    bool has_zero = (d1 == 0) || (d2 == 0) || (d3 == 0);

    if (has_zero)
        return (false);
    return !(has_neg && has_pos);
}
