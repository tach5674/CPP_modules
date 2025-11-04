#include "Point.hpp"

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point tests[] = {
        Point(3, 3),    // inside
        Point(10, 10),  // outside
        Point(5, 0),    // on edge
        Point(0, 0),    // vertex
        Point(-1, 5)    // outside
    };

    for (int i = 0; i < 5; i++) {
        std::cout << "Point " << i << " " 
                  << (bsp(a, b, c, tests[i]) ? "inside" : "outside")
                  << std::endl;
    }
}
