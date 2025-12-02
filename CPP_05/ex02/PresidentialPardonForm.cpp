#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target_("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &t) : AForm("PresidentialPardonForm", 25, 5), target_(t) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target_(other.target_) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute() const
{
    std::cout << this->target_ << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}