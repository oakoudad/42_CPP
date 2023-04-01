#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog default Constructor." << std::endl;
}

Dog   &Dog::operator =(const Dog &rhs)
{
    std::cout << "Dog Copy Assignment operator." << std::endl;
    if (&rhs != this)
    {
        delete this->brain;
        this->brain = new Brain(*rhs.brain);
        this->type = rhs.type;
    }
    return (*this);
}

Dog::Dog( const Dog &obj ){
    std::cout << "Dog Copy Constructor." << std::endl;
    *this = obj;
}

std::string Dog::getType() const
{
    return (type);
}

std::string Dog::getIdea(int index) const
{
    return (this->brain->getIdea(index));
}

void Dog::makeSound() const
{
    std::cout << "Hau, hau (Dog sound)." << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor." << std::endl;
    delete this->brain;
}