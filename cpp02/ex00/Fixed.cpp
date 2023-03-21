#include "Fixed.hpp"

Fixed::Fixed()
{
    this->fixedPoint = 0;
    std::cout << "Default constructor called." << std::endl;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called." << std::endl;
}

int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called." << std::endl;
    return this->fixedPoint;
}

Fixed   &Fixed::operator =(const Fixed &rhs)
{
    std::cout << "Copy assignment operator called." << std::endl;
    if (&rhs != this)
        this->fixedPoint = rhs.getRawBits();
    return (*this);
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called." << std::endl;
    *this = obj;
}


void    Fixed::setRawBits( int const raw )
{
    this->fixedPoint = raw;
}