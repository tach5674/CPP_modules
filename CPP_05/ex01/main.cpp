#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat b1 = Bureaucrat("Robert", 10);
    Bureaucrat b2 = Bureaucrat("Tom", 30);
    Form f = Form("C8", 20, 5);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << f << std::endl;

    b2.signForm(f);
    b1.signForm(f);

    std::cout << f << std::endl;
    
    return 0;
}