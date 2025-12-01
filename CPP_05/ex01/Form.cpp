#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name_("Blank"), signed_(false), sign_grade_(150), execute_grade_(150) {}

Form::Form(std::string n, int sg, int eg) : name_(n), signed_(false), sign_grade_(sg), execute_grade_(eg)
{
    if (sign_grade_ < 1 || execute_grade_ < 1)
        throw Form::GradeTooHighException();
    if (sign_grade_ > 150 || execute_grade_ > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : name_(other.name_), signed_(other.signed_), sign_grade_(other.sign_grade_), execute_grade_(other.execute_grade_) {}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->signed_ = other.signed_;
    return *this;
}

Form::~Form() {}

const char *Form::GradeTooHighException::what() const throw()
{
    return "the grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "the grade is too low";
}

std::string Form::getName() const
{
    return this->name_;
}

int Form::getSignGrade() const
{
    return this->sign_grade_;
}

int Form::getExecuteGrade() const
{
    return this->execute_grade_;
}

bool Form::getSignState() const
{
    return this->signed_;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= this->getSignGrade())
        this->signed_ = true;
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << f.getName()
       << ", minimum sign grade " << f.getSignGrade()
       << ", minimum execute grade " << f.getExecuteGrade()
       << ", Signed: " << std::boolalpha << f.getSignState() << std::noboolalpha;
    return os;
}