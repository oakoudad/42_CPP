#include "Character.hpp"

Character::Character():name("<Without name>"){
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
        this->name = rhs.name;
        for(int i = 0; i < 4; i++)
            if (rhs.slot[i] != NULL)
                this->slot[i] = rhs.slot[i]->clone();
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
            slot[i] = m->clone();
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (slot[idx] != NULL)
        delete slot[idx];
    slot[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
    {
        std::cerr << "This index is invalid (the index between 0-3)." << std::endl;
        return ;
    }
    if (slot[idx] == NULL)
    {
        std::cerr << "Slot #" << std::to_string(idx) << " is Empty." << std::endl;
        return ;
    }
    this->slot[idx]->use(target);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (slot[i] != NULL)
            delete slot[i];
    }
}