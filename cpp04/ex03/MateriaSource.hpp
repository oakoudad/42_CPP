#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"

class MateriaSource
{
    public:
        MateriaSource();
        MateriaSource( const MateriaSource &obj );
        MateriaSource &operator =(const MateriaSource &rhs);

        void        learnMateria(AMateria*);
        AMateria*   createMateria(std::string const & type);
        ~MateriaSource();
};

#endif