#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &gun) : gun(gun)
{
    this->name = name;
}

HumanA::~HumanA()
{
    std::cout << "HumanA Destructed" << std::endl;
}

void    HumanA::attack()const
{
    std::cout << name << " attacks with their " << gun.getType() << std::endl;
}