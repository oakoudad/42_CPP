#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
    private:
        AMateria *save[4];
    public:
        MateriaSource();
        MateriaSource( const MateriaSource &obj );
        MateriaSource &operator =(const MateriaSource &rhs);

        void        learnMateria(AMateria *m);
        AMateria*   createMateria(std::string const & type);
        ~MateriaSource();
};

#endif