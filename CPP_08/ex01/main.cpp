#include "Span.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));
    unsigned int n = 10;

    Span s = Span(n);
    for (unsigned int i = 0; i < 5; i++)
        s.addNumber(std::rand() % 100);
    s.printNumbers();
    s.fillSpan(3);
    s.printNumbers();
    std::cout << "Shortes span - " << s.shortestSpan() << std::endl;
    std::cout << "Longest span - " << s.longestSpan() << std::endl;
    return 0;
}