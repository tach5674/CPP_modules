#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Blank", 145, 137), target_("") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string n) : AForm(n, 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : name_(other.name_), signed_(other.signed_), sign_grade_(other.sign_grade_), execute_grade_(other.execute_grade_) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        this->signed_ = other.signed_;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const char *ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
    return "the grade is too high";
}

const char *ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
    return "the grade is too low";
}

std::string ShrubberyCreationForm::getName() const
{
    return this->name_;
}

int ShrubberyCreationForm::getSignGrade() const
{
    return this->sign_grade_;
}

int ShrubberyCreationForm::getExecuteGrade() const
{
    return this->execute_grade_;
}

bool ShrubberyCreationForm::getSignState() const
{
    return this->signed_;
}

void ShrubberyCreationForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= this->getSignGrade())
        this->signed_ = true;
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &f)
{
    os << f.getName()
       << ", minimum sign grade " << f.getSignGrade()
       << ", minimum execute grade " << f.getExecuteGrade()
       << ", Signed: " << std::boolalpha << f.getSignState() << std::noboolalpha;
    return os;
}