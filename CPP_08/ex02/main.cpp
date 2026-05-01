#include "MutantStack.hpp"
#include <iostream>
#include <vector>
int main()
{
    MutantStack<int> s;
    s.push(5);
    s.push(7);
    s.push(4);
    MutantStack<int>::iterator it = s.begin();
    while (it < s.end())
        std::cout << *it++ << "\n";
    const MutantStack<int> cs = s;
    MutantStack<int>::const_iterator cit = cs.begin();
    while (cit < cs.end())
        std::cout << *cit++ << "\n";
    return 0;
}