#include "Zombie.hpp"

int main()
{
    Zombie *p = newZombie("Test 01");
    p->announce(); 
    delete(p);
    randomChump("Test 02");
    return (0);
}
