#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <set>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> v(arr, arr + 5);
    std::list<int> l(arr, arr + 5);
    std::set<int> s(arr, arr + 5);

    try
    {
        std::cout << *easyfind(v, 1) << std::endl;
    }
    catch (...)
    {
        std::cout << "Value not found!\n";
    }
    try
    {
        std::cout << *easyfind(l, 7) << std::endl;
    }
    catch (...)
    {
        std::cout << "Value not found!\n";
    }
    try
    {
        std::cout << *easyfind(s, 3) << std::endl;
    }
    catch (...)
    {
        std::cout << "Value not found!\n";
    }
    return 0;
}