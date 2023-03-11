#include "Zombie.hpp"

int main()
{
    int n = 0;
    Zombie *p = zombieHorde(n, "Omar");

    for(int i = 0; i < n; i++)
        p[i].announce();
    delete []p;
    return (0);
}
