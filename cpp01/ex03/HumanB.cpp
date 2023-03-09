#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB( std::string the_name)
{
    gun = NULL;
    name = the_name;
}

HumanB::~HumanB()
{
    std::cout << "HumanB Destructed" << std::endl;
}

void    HumanB::setWeapon(Weapon &the_gun)
{
    gun = &the_gun;
}

void    HumanB::attack()const
{
    if (gun)
        std::cout << name << " attacks with their " << gun->getType() << std::endl;
    else
        std::cout << name << " attacks with their No-Gun" << std::endl;
}