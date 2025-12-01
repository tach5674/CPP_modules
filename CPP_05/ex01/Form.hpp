#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
private:
    const std::string name_;
    bool signed_;
    const int sign_grade_;
    const int execute_grade_;

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

    Form();
    Form(std::string n, int sg, int eg);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    std::string getName() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    bool getSignState() const;
    void beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &os, const Form &b);

#endif