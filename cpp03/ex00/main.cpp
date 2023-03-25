#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("TheClap");

    clapTrap.attack("Enemy");
    clapTrap.attack("Enemy");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(10);
    clapTrap.beRepaired(5);
    clapTrap.takeDamage(15);
    clapTrap.beRepaired(10);
    clapTrap.takeDamage(5);
    clapTrap.attack("Enemy");
    clapTrap.attack("Enemy");
    clapTrap.attack("Enemy");
    clapTrap.attack("Enemy");
    clapTrap.attack("Enemy");
    clapTrap.attack("Enemy");
    clapTrap.takeDamage(5);
    
    clapTrap.beRepaired(10);
    return 0;
}
