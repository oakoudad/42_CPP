#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie random_zombie(name);
    
    random_zombie.announce();
}