#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat
{
private:
    const std::string name_;
    int grade_;

public:
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    Bureaucrat();
    Bureaucrat(std::string n, int g);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    const std::string getName() const;
    int getGrade() const;
    void incGrade();
    void decGrade();
    void signForm(AForm &form) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif