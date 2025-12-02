#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
    
int main()
{
    Bureaucrat b = Bureaucrat("Robert", 1);
    Intern i = Intern();
    AForm *s = i.makeForm("shrubbery creation", "home");
    AForm *r = new RobotomyRequestForm("home");
    AForm *p = new PresidentialPardonForm("Gago");
    std::cout << b << std::endl;
    std::cout << *s << std::endl;
    std::cout << *r << std::endl;
    std::cout << *p << std::endl;
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
    b.signForm(*s);
    b.signForm(*r);
    b.signForm(*p);
    std::cout << *s << std::endl;
    std::cout << *r << std::endl;
    std::cout << *p << std::endl;
    b.executeForm(*s);
    b.executeForm(*r);
    b.executeForm(*p);
    delete s;
    delete r;
    delete p;
    return 0;
}