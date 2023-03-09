#include "Weapon.hpp"

Weapon::Weapon(){
    
}

Weapon::~Weapon(){
    
}

Weapon::Weapon( std::string new_type )
{
    type = new_type;
}

const std::string  &Weapon::getType( void )const
{
    return type;
}

void Weapon::setType( std::string new_type )
{
    type = new_type;
}

