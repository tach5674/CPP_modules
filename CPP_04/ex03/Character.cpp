#include "Character.hpp"

Character::Character() : name_("")
{
    for (size_t i = 0; i < slots_size_; i++)
        slots_[i] = NULL;
    for (size_t i = 0; i < floor_size_; i++)
        floor_[i] = NULL;
}

Character::Character(const std::string &name) : name_(name)
{
    for (size_t i = 0; i < slots_size_; i++)
        slots_[i] = NULL;
    for (size_t i = 0; i < floor_size_; i++)
        floor_[i] = NULL;
}

Character::Character(const Character &other) : name_(other.name_)
{
    for (size_t i = 0; i < slots_size_; i++)
        slots_[i] = other.slots_[i] ? other.slots_[i]->clone() : NULL;
}

Character &Character::operator=(const Character &other)
{
    name_ = other.name_;
    for (size_t i = 0; i < slots_size_; i++)
    {
        if (slots_[i])
            delete slots_[i];
        slots_[i] = other.slots_[i] ? other.slots_[i]->clone() : NULL;
    }
    return *this;
}

Character::~Character()
{
    for (size_t i = 0; i < slots_size_; i++)
    {
        if (slots_[i])
            delete slots_[i];
    }
    for (size_t i = 0; i < floor_size_; i++)
    {
        if (floor_[i])
            delete floor_[i];
    }
}

std::string const &Character::getName() const
{
    return name_;
}

void Character::equip(AMateria *m)
{
    for (size_t i = 0; i < slots_size_; i++)
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
    for (size_t i = 0; i < floor_size_; i++)
    {
        if (!floor_[i])
        {
            floor_[i] = slots_[idx];
            break;
        }
    }
    slots_[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (slots_[idx])
        slots_[idx]->use(target);
}
