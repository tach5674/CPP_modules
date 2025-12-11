#include "MutantStack.hpp"
#include <iostream>

int main()
{
    MutantStack<int> s;
    s.push(5);
    s.push(7);
    s.push(4);
    std::cout << s.top();
    MutantStack<int>::iterator b = s.begin();
    MutantStack<int>::iterator e = s.end();
    while (b < e)
        std::cout << *b++ << std::endl;
    return 0;
}