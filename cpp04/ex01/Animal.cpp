#include "Animal.hpp"

Animal::Animal():type("Animal")
{
    std::cout << "Animal default Constructor." << std::endl;
}

Animal   &Animal::operator =(const Animal &rhs)
{
    std::cout << "Animal Copy Assignment operator." << std::endl;
    if (&rhs != this)
        this->type = rhs.type;
    return (*this);
}

Animal::Animal( const Animal &obj ){
    std::cout << "Animal Copy Constructor." << std::endl;
    *this = obj;
}

void Animal::makeSound() const
{
    std::cout << "General sound for Animal." << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}

Animal::~Animal()
{
    std::cout << "Animal destructor." << std::endl;
}