#include "Ice.hpp"

Ice::Ice():AMateria("ice"){}

Ice &Ice::operator =(const Ice &rhs)
{
    (void)rhs;
    return (*this);
}

Ice::Ice( const Ice &obj ){
    *this = obj;
}

AMateria* Ice::clone() const
{
    AMateria *tmp = new Ice();
    return (tmp);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice(){}
