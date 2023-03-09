#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA( std::string the_name, Weapon &the_gun):gun(the_gun)
{
    name = the_name;
}

HumanA::~HumanA()
{
    std::cout << "HumanA Destructed" << std::endl;
}

void    HumanA::attack()const
{
    std::cout << name << " attacks with their " << gun.getType() << std::endl;
}