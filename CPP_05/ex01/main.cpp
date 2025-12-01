#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat b = Bureaucrat("Robert", 10);
    Form f = Form("C8", 20, 5);
    std::cout << b << std::endl;
    std::cout << f << std::endl;
    // for (size_t i = 0; i < 150; i++)
    // {
    //     try
    //     {
    //         b.incGrade();
    //     }
    //     catch(std::exception &e)
    //     {
    //         std::cerr << e.what() << std::endl;
    //     }
    // }
    b.signForm(f);
    std::cout << f << std::endl;
    return 0;
}