#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern() {}

static AForm *createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

static AForm *createPardon(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidental pardon",
    };

    AForm *(*funcs[3])(const std::string &) = {
        &createShrubbery,
        &createRobotomy,
        &createPardon,
    };

    for (size_t i = 0; i < 3; i++)
    {
        if (names[i] == name)
        {
            std::cout << "Intern creates " << name << " form" << std::endl;
            return funcs[i](target);
        }
    }
    std::cout << "Form with this name does no exist!" << std::endl;
    return NULL;
}