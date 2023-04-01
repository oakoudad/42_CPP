#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat default Constructor." << std::endl;
}

Cat   &Cat::operator =(const Cat &rhs)
{
    std::cout << "Cat Copy Assignment operator." << std::endl;
    if (&rhs != this)
    {
        this->type = rhs.type;
        delete this->brain;
        this->brain = new Brain(*rhs.brain);
    }
    return (*this);
}

Cat::Cat( const Cat &obj ){
    std::cout << "Cat Copy Constructor." << std::endl;
    *this = obj;
}

std::string Cat::getIdea(int index) const
{
    return (this->brain->getIdea(index));
}

void Cat::makeSound() const
{
    std::cout << "Meow, meow (Cat sound)." << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor." << std::endl;
    delete this->brain;
}