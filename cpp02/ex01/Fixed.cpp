#include "Fixed.hpp"

float   power(int nbr, int e)
{
    float   r;
    int     s;

    s = 1;
    r = 1;
    if (e < 0)
    {
        s = -1;
        e *= -1;
    }
    while (e > 0)
    {
        r *= nbr;
        e--;
    }
    if (s == -1)
        return (1/r);
    return r;
}

Fixed::Fixed()
{
    this->fixedPoint = 0;
    std::cout << "Default constructor called." << std::endl;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called." << std::endl;
}


Fixed   &Fixed::operator =(const Fixed &rhs)
{
    std::cout << "Copy assignment operator called." << std::endl;
    if (&rhs != this)
        this->fixedPoint = rhs.fixedPoint;
    return (*this);
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called." << std::endl;
    *this = obj;
}

Fixed::Fixed( const int nbr )
{
    std::cout << "Int constructor called." << std::endl;
    this->fixedPoint = nbr * power(2, this->fractionalBits);
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called." << std::endl;
	this->fixedPoint = std::roundf(nbr * power(2, this->fractionalBits));
}

void    Fixed::setRawBits( int const raw )
{
    this->fixedPoint = raw;
}

int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called." << std::endl;
    return this->fixedPoint;
}

float   Fixed::toFloat( void ) const
{
    return (this->fixedPoint * power(2, -1 * this->fractionalBits));
}

int     Fixed::toInt( void ) const
{
    return (this->fixedPoint * power(2, -1 * this->fractionalBits));
}


std::ostream& operator<<(std::ostream &COUT, Fixed const &rhs)
{
	COUT << rhs.toFloat();
	return COUT;
}