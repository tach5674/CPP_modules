#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (size_t i = 0; i < slots_size_; i++)
        slots_[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (size_t i = 0; i < slots_size_; i++)
    {
        if (slots_[i])
            delete slots_[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (size_t i = 0; i < slots_size_; i++)
        slots_[i] = other.slots_[i] ? other.slots_[i]->clone() : NULL;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    for (size_t i = 0; i < slots_size_; i++)
    {
        if (slots_[i])
            delete slots_[i];
        slots_[i] = other.slots_[i] ? other.slots_[i]->clone() : NULL;
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (size_t i = 0; i < slots_size_; i++)
    {
        if (!slots_[i])
        {
            slots_[i] = m;
            break;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (size_t i = 0; i < slots_size_; i++)
    {
        if (slots_[i]->getType() == type)
            return slots_[i]->clone();
    }
    return NULL;
}
