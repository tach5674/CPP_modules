#include "AMateria.hpp"

AMateria::AMateria() : type_("") {}

AMateria::AMateria(std::string const &type) : type_(type) {}

AMateria::AMateria(const AMateria &other) : type_(other.type_) {}

AMateria &AMateria::operator=(const AMateria &other)
{
    (void)other;
    return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const
{
    return type_;
}