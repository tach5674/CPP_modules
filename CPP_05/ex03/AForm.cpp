#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name_("Blank"), signed_(false), sign_grade_(150), execute_grade_(150) {}

AForm::AForm(const std::string &n, const int &sg, const int &eg) : name_(n), signed_(false), sign_grade_(sg), execute_grade_(eg)
{
    if (sign_grade_ < 1 || execute_grade_ < 1)
        throw AForm::GradeTooHighException();
    if (sign_grade_ > 150 || execute_grade_ > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : name_(other.name_), signed_(other.signed_), sign_grade_(other.sign_grade_), execute_grade_(other.execute_grade_) {}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        this->signed_ = other.signed_;
    return *this;
}

AForm::~AForm() {}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "the grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "the grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "the form is not signed";
}

std::string AForm::getName() const
{
    return this->name_;
}

int AForm::getSignGrade() const
{
    return this->sign_grade_;
}

int AForm::getExecuteGrade() const
{
    return this->execute_grade_;
}

bool AForm::getSignState() const
{
    return this->signed_;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= this->getSignGrade())
        this->signed_ = true;
    else
        throw GradeTooLowException();
}

void AForm::execute(const Bureaucrat &b) const
{
    if (!this->getSignState())
        throw FormNotSignedException();
    if (b.getGrade() > this->getExecuteGrade())
        throw GradeTooLowException();
    execute();
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << f.getName()
       << ", minimum sign grade " << f.getSignGrade()
       << ", minimum execute grade " << f.getExecuteGrade()
       << ", Signed: " << std::boolalpha << f.getSignState() << std::noboolalpha;
    return os;
}