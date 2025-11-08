#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    std::string name_;
    static const size_t slots_size_ = 4;
    static const size_t floor_size_ = 10;
    AMateria *slots_[slots_size_];
    AMateria *floor_[floor_size_];

public:
    Character();
    Character(const std::string &name);
    Character(const Character &other);
    Character &operator=(const Character &other);
    ~Character();

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

#endif