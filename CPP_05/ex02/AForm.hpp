#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
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

    AForm();
    AForm(std::string n, int sg, int eg);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    ~AForm();

    std::string getName() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    bool getSignState() const;
    void beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &os, const AForm &b);

#endif