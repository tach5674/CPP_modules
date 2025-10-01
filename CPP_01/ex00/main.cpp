#include "Zombie.h"

int main()
{
    Zombie z1 = Zombie("Kapik");
    Zombie z2 = Zombie("Kovik");
    z1.announce();
    z1 = z2;
    z1.announce();
    randomChump("Ul");
    Zombie *zp = newZombie("Dzuk");
    zp->announce();
    delete(zp);
}
