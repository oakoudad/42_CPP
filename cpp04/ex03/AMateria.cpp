#include "AMateria.hpp"

AMateria::AMateria():type(""){}

AMateria::AMateria(std::string const & type):type(type){}

std::string const &AMateria::getType() const
{
    return (type);
}

AMateria &AMateria::operator =(const AMateria &rhs)
{
    (void)rhs;
    return (*this);
}

AMateria::AMateria(const AMateria &rhs)
{
    *this = rhs;
}

void AMateria::use(ICharacter& target)
{
    if (this->type == "ice")
        std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    else if(this->type == "cure")
        std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

AMateria::~AMateria(){}