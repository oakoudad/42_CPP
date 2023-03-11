#include "HumanB.hpp"

HumanB::HumanB( std::string name)
{
    gun = NULL;
    this->name = name;
}

HumanB::~HumanB()
{
    std::cout << "HumanB Destructed" << std::endl;
}

void    HumanB::setWeapon(Weapon &gun)
{
    this->gun = &gun;
}

void    HumanB::attack()const
{
    if (gun)
        std::cout << name << " attacks with their " << gun->getType() << std::endl;
    else
        std::cout << name << " attacks with their No-Gun" << std::endl;
}