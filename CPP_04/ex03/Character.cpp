#include "Character.hpp"

Character::Character() : name_("")
{
    for (size_t i = 0; i < size_; i++)
        slots_[i] = NULL;
}

Character::Character(const std::string &name) : name_(name)
{
    for (size_t i = 0; i < size_; i++)
        slots_[i] = NULL;
}

Character::Character(const Character &other)
{
    for (size_t i = 0; i < size_; i++)
        slots_[i] = other.slots_[i] ? other.slots_[i]->clone() : NULL;
}

Character &Character::operator=(const Character &other)
{
    for (size_t i = 0; i < size_; i++)
    {
        if (slots_[i])
            delete slots_[i];
        slots_[i] = other.slots_[i] ? other.slots_[i]->clone() : NULL;
    }
    return *this;
}

Character::~Character()
{
    for (size_t i = 0; i < size_; i++)
    {
        if (slots_[i])
            delete slots_[i];
    }
}

std::string const &Character::getName() const
{
    return name_;
}

void Character::equip(AMateria *m)
{
    for (size_t i = 0; i < size_; i++)
    {
        if (!slots_[i])
        {
            slots_[i] = m;
            return;
        }
    }
}
void Character::unequip(int idx)
{
    slots_[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    slots_[idx]->use(target);
}
