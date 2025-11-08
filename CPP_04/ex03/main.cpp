#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

int main()
{
    AMateria *c = new Cure();
    AMateria *i = new Ice();

    // std::cout << c->getType() << std::endl << i->getType() << std::endl;

    // delete c;
    // delete i;

    ICharacter *me = new Character("me");
    ICharacter *bob = new Character("bob");

    me->equip(c);
    me->equip(i);

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    
    return 0;
}