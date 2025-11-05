#include "ScavTrap.hpp"

int main()
{
    ScavTrap clap1("Clappy");
    ScavTrap clap2("Trapster");

    clap1.attack("Target1");
    clap2.takeDamage(5);
    clap2.beRepaired(3);
    clap1.attack("Target2");
    clap2.takeDamage(10);
    clap2.beRepaired(5);
    clap1.guardGate();
    return 0;
}