#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria &rhs);
        AMateria &operator =(const AMateria &rhs);

        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);

        virtual ~AMateria();
};

#endif