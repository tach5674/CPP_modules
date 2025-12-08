#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data *a = new Data;

    a->i = 10;
    std::cout << "Address of a: " << a << std::endl;
    std::cout << "Value in a: " << a->i << std::endl;

    Data *b = Serializer::deserialize(Serializer::serialize(a));

    b->i = 5;
    std::cout << "Address of b: " << b << std::endl;
    std::cout << "Value in a: " << a->i << std::endl;

    delete a;
    return 0;
}
