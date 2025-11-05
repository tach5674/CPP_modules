#include "FragTrap.hpp"

int main()
{
    FragTrap clap1("Clappy");
    FragTrap clap2("Trapster");

    clap1.attack("Target1");
    clap2.takeDamage(5);
    clap2.beRepaired(3);
    clap1.attack("Target2");
    clap2.takeDamage(10);
    clap2.beRepaired(5);
    clap1.highFivesGuys();
    return 0;
}