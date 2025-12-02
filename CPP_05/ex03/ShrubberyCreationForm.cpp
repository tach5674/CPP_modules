#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target_("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &t) : AForm("ShrubberyCreationForm", 145, 137), target_(t) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target_(other.target_) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute() const
{
    std::string filename = target_ + "_shrubbery";
    std::ofstream ofs(filename.c_str());

    if (!ofs)
        return;

    ofs << "        ccee88oo\n"
           "  C8O8O8Q8PoOb o8oo\n"
           " dOB69QO8PdUOpugoO9bD\n"
           " CgggbU8OU qOp qOdoUOdcb\n"
           "    6OuU  /p u gcoUodpP\n"
           "      \\\\//  /douUP\n"
           "        \\\\////\n"
           "         |||/\\\n"
           "         |||\\/\n"
           "         |||||\n"
           "   .....//||||\\....\n";
    ofs.close();
}