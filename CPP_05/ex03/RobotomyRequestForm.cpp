#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 75, 45), target_("") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &t) : AForm("RobotomyRequestForm", 75, 45), target_(t) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target_(other.target_) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute() const
{
    std::srand(std::time(NULL));
    std::cout << "***Drilling noises***" << std::endl;
    if (std::rand() % 2)
        std::cout << this->target_ << " has been robotomized successfully!" << std::endl;
    else
        std::cout << this->target_ << " robotomization failed!" << std::endl;
        
}