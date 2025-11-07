#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "------------------------------------" << std::endl;

    size_t n = 10;
    Animal *data[n];

    for (size_t i = 0; i < n; i++)
    {
        if (i % 2)
            data[i] = new Dog();
        else
            data[i] = new Cat();
    }
    for (size_t i = 0; i < n; i++)
        delete data[i];

    std::cout << "------------------------------------" << std::endl;

    Dog *d1 = new Dog();
    Dog *d2 = new Dog();
    Dog *d3 = new Dog(*d2);
    *d1 = *d2;
    delete d1;
    delete d2;
    delete d3;

    std::cout << "------------------------------------" << std::endl;
    
    return 0;
}
