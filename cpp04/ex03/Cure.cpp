#include "Cure.hpp"

Cure::Cure():AMateria("cure"){}

Cure &Cure::operator =(const Cure &rhs)
{
    (void)rhs;
    return (*this);
}

Cure::Cure( const Cure &obj ){
    *this = obj;
}

AMateria* Cure::clone() const
{
    AMateria *tmp = new Cure();
    return (tmp);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure::~Cure(){}