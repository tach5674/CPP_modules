#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    static const size_t slots_size_ = 4;
    AMateria *slots_[slots_size_];

public:
    MateriaSource();
    MateriaSource(const MateriaSource &other);
    MateriaSource &operator=(const MateriaSource &other);
    ~MateriaSource();

    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &type);
};

#endif