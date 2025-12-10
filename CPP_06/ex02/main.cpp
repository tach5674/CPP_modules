#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));
    Base *b = generate();
    Base &bref = *b;
    identify(b);
    identify(bref);
    delete b;
    return 0;
}
