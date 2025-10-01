#include "Zombie.h"

int main()
{
    int N = 5;

    Zombie z1 = Zombie("Kapik");
    Zombie z2 = Zombie("Kovik");
    z1.announce();
    z1 = z2;
    z1.announce();
    
    Zombie *horde = zombieHorde(N, "Dzuk");
    for (int i = 0; i < N; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
}
