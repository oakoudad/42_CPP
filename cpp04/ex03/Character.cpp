#include "Character.hpp"

Character::Character():name(""){
    for (int i = 0; i < 4; i++)
        slot[i] = NULL;
}

Character::Character( const std::string &name ):name(name){
    for (int i = 0; i < 4; i++)
        slot[i] = NULL;
}

Character &Character::operator =(const Character &rhs)
{
    if (&rhs != this)
    {
        this->name = rhs.getName();
        for(int i = 0; i < 4; i++)
            this->slot[i] = rhs.slot[i];
    }
    return (*this);
}

Character::Character( const Character &obj )
{
    *this = obj;
}

std::string const   &Character::getName() const
{
    return (name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (slot[i] == NULL)
        {
            slot[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    slot[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "This index is invalid (the index between 0-3)" << std::endl;
        return ;
    }
    this->slot[idx]->use(target);
}

Character::~Character(){}