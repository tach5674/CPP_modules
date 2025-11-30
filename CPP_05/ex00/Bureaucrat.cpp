#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("Anonymus"), grade_(150) {}

Bureaucrat::Bureaucrat(std::string n, int g) : name_(n)
{
    if (g < 1)
        throw Bureaucrat::GradeTooHighException();
    if (g > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade_ = g;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->name_ = other.name_;
        this->grade_ = other.grade_;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::string Bureaucrat::getName() const
{
    return this->name_;
}

int Bureaucrat::getGrade() const
{
    return this->grade_;
}

void Bureaucrat::incGrade()
{
    if (grade_ == 150)
        throw Bureaucrat::GradeTooHighException();
    this->grade_++;
}

void Bureaucrat::decGrade()
{
    if (grade_ == 1)
        throw Bureaucrat::GradeTooLowException();
    this->grade_--;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}