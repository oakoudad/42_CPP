#include "ScavTrap.hpp"

int main()
{
    ScavTrap scavTrap("Frag_00");
    
    scavTrap.guardGate();
    for(int i = 0; i < 100; i++)
        scavTrap.attack("enemy");
    scavTrap.beRepaired(10);
    return 0;
}