#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():type("WrongAnimal")
{
    std::cout << "WrongAnimal default Constructor." << std::endl;
}

WrongAnimal   &WrongAnimal::operator =(const WrongAnimal &rhs)
{
    std::cout << "WrongAnimal Copy Assignment operator." << std::endl;
    if (&rhs != this)
        this->type = rhs.type;
    return (*this);
}

WrongAnimal::WrongAnimal( const WrongAnimal &obj ){
    std::cout << "WrongAnimal Copy Constructor." << std::endl;
    *this = obj;
}

void WrongAnimal::makeSound() const
{
    std::cout << "General sound for WrongAnimal." << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (type);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor." << std::endl;
}