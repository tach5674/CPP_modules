#include "Base.hpp"
#include <iostream>

int main()
{
    Base *b = generate();
    Base &bref = *b;
    identify(b);
    identify(bref);
    delete b;
    return 0;
}
