#include "iter.hpp"

template<typename T>
void sqr(T &val)
{
    val = val * val;
}

template<typename T>
void prt(const T &val)
{
    std::cout << val << std::endl;
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};

    iter(arr, 5, prt<int>);
    iter(arr, 5, sqr<int>);
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    
    return 0;
}