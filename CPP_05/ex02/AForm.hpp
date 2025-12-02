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

    class FormNotSignedException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    AForm();
    AForm(const std::string &n, const int &sg, const int &eg);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    std::string getName() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    bool getSignState() const;
    void beSigned(const Bureaucrat &b);

    void execute(const Bureaucrat &b) const;

protected:
    virtual void execute() const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &b);

#endif