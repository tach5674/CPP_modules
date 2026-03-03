#include "iter.hpp"

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};

    iter(arr, 5, prt<int>);
    iter(arr, 5, sqr<int>);
    std::cout << "---------------\n";
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    
    return 0;
}