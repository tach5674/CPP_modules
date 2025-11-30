#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b = Bureaucrat("Robert", 10);
    std::cout << b << std::endl;
    for (size_t i = 0; i < 150; i++)
    {
        try
        {
            b.incGrade();
        }
        catch(std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << b << std::endl;
    return 0;
}