#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon();
        HumanB jim("Jim");
        jim.attack();
        jim.setWeapon(club);
        club.setType("crude spiked club");
        jim.attack();
    }
    return 0;
}