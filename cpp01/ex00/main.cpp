#include "Zombie.hpp"

int main()
{
    Zombie *p = newZombie("Omar");
    p->announce(); 
    randomChump("Akoudad");
    delete(p);
}
