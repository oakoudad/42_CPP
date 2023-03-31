#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat default Constructor." << std::endl;
}

WrongCat   &WrongCat::operator =(const WrongCat &rhs)
{
    std::cout << "WrongCat Copy Assignment operator." << std::endl;
    if (&rhs != this)
        this->type = rhs.type;
    return (*this);
}

WrongCat::WrongCat( const WrongCat &obj ){
    std::cout << "WrongCat Copy Constructor." << std::endl;
    *this = obj;
}

void WrongCat::makeSound() const
{
    std::cout << "Wrong meow, meow (WrongCat sound)." << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor." << std::endl;
}