#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    for (int i = 0; i < 4; i++)
        save[i] = NULL;
}

MateriaSource &MateriaSource::operator =(const MateriaSource &rhs)
{
    for (int i = 0; i < 4; i++)
        if (this->save[i] != NULL)
        {
            delete this->save[i];
            this->save[i] = rhs.save[i]->clone();
        }
    return (*this);
}

MateriaSource::MateriaSource( const MateriaSource &obj )
{
    *this = obj;
}

void        MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
        if (save[i] == NULL)
        {
            save[i] = m;
            return ;
        }
    
    std::cerr << "Slots is full." << std::endl;
}

AMateria*   MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
        if (save[i] != NULL && save[i]->getType() == type)
            return (save[i]->clone());
    std::cerr << "This type not found." << std::endl;
    return (0);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        if (save[i] != NULL)
            delete (save[i]);
}
