#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

// int main()
// {
//     AMateria *c = new Cure();
//     AMateria *i = new Ice();

//     // std::cout << c->getType() << std::endl << i->getType() << std::endl;

//     // delete c;
//     // delete i;

//     ICharacter *me = new Character("me");
//     ICharacter *bob = new Character("bob");

//     me->equip(c);
//     me->equip(i);

//     me->use(0, *bob);
//     me->use(1, *bob);

//     me->unequip(0);

//     me->use(0, *bob);
//     delete bob;
//     delete me;

//     return 0;
// }

int main()
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}