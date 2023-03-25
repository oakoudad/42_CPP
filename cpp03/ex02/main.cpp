#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    FragTrap fragTrap("Frag_00");
    
    fragTrap.highFivesGuys();
    for(int i = 0; i < 100; i++)
        fragTrap.attack("enemy");
    fragTrap.beRepaired(10);
    return 0;
}
