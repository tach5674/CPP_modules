#include "Array.hpp"

int main(void)
{
    Array<int> arr = Array<int>(5);
    arr[2] = 10;
    // arr[5] = 5;
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << std::endl;
    
    return 0;
}