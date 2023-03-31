#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character: public ICharacter
{
    protected:
        std::string name;
        AMateria    *slot[4];

    public:
        Character();
        Character( const std::string &name );
        Character( const Character &obj );
        Character &operator =(const Character &rhs);

        std::string const   &getName() const;
        void                equip(AMateria* m);
        void                unequip(int idx);
        void                use(int idx, ICharacter& target);
        AMateria            *getMateria(int idx);
        ~Character();
};


#endif