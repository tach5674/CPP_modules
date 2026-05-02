#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    try
    {
        if (argc < 2)
        {
            std::cerr << "Error: Wrong number of arguments.\n";
            std::cerr << "Usage: " << argv[0] << " <positive integers>\n";
            return 1;
        }

        PmergeMe pmergeMe;
        pmergeMe.prepareData(const_cast<const char **>(argv + 1));
        pmergeMe.printVector("Before");
        std::clock_t vectorTime = pmergeMe.sortVector();
        std::clock_t dequeTime = pmergeMe.sortDeque();
        pmergeMe.printVector("After");
        std::cout << "Time to process a range of " << pmergeMe.getSize()
                  << " elements with std::vector : " << vectorTime << " μs\n";
        std::cout << "Time to process a range of " << pmergeMe.getSize()
                  << " elements with std::deque : " << dequeTime << " μs\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}