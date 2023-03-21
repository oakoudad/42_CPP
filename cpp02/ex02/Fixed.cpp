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
}
Fixed::~Fixed(){}

Fixed::Fixed(const Fixed &obj)
{
    *this = obj;
}

Fixed::Fixed( const int nbr )
{
    this->fixedPoint = nbr * power(2, this->fractionalBits);
}

Fixed::Fixed(const float nbr)
{
	this->fixedPoint = std::roundf(nbr * power(2, this->fractionalBits));
}

void    Fixed::setRawBits( int const raw )
{
    this->fixedPoint = raw;
}

int     Fixed::getRawBits( void ) const
{
    return this->fixedPoint;
}

float   Fixed::toFloat( void ) const
{
    return (this->fixedPoint / power(2, this->fractionalBits));
}

int     Fixed::toInt( void ) const
{
    return (this->fixedPoint / power(2, this->fractionalBits));
}

Fixed   &Fixed::operator =(const Fixed &rhs)
{
    if (&rhs != this)
        this->fixedPoint = rhs.fixedPoint;
    return (*this);
}

Fixed   Fixed::operator *(const Fixed &rhs)
{
    Fixed tmp;

    long l = this->fixedPoint * rhs.fixedPoint;
    l /= power(2, this->fractionalBits);
    tmp.fixedPoint = l; 
    
	return (tmp);
}

Fixed   Fixed::operator /(const Fixed &rhs)
{
    Fixed tmp;

    long l = (this->fixedPoint * power(2, this->fractionalBits) / rhs.fixedPoint);
    tmp.fixedPoint = l; 
	return (tmp);
}

Fixed   Fixed::operator +(const Fixed &rhs)
{
    Fixed tmp;

    long l = this->fixedPoint + rhs.fixedPoint;
    tmp.fixedPoint = l; 
	return (tmp);
}

Fixed   Fixed::operator -(const Fixed &rhs)
{
    Fixed tmp;

    long l = this->fixedPoint - rhs.fixedPoint;
    tmp.fixedPoint = l;
	return (tmp);
}

bool   Fixed::operator >(const Fixed &rhs)
{
	return (this->fixedPoint > rhs.fixedPoint);
}
bool    Fixed::operator  >=(const Fixed &rhs){
    return (this->fixedPoint >= rhs.fixedPoint);
}

bool    Fixed::operator  <(const Fixed &rhs){
    return (this->fixedPoint < rhs.fixedPoint);
}

bool    Fixed::operator  <=(const Fixed &rhs){
    return (this->fixedPoint <= rhs.fixedPoint);
}

bool    Fixed::operator  ==(const Fixed &rhs){
    return (this->fixedPoint == rhs.fixedPoint);
}

bool    Fixed::operator  !=(const Fixed &rhs){
    return (this->fixedPoint != rhs.fixedPoint);
}



Fixed   &Fixed::operator   ++(void)
{
    this->fixedPoint += 1;
    return (*this);
}

Fixed   Fixed::operator ++(int)
{
	Fixed tmp(*this);
	this->fixedPoint += 1;
	return (tmp);
}



Fixed   &Fixed::operator  --(void)
{
    this->fixedPoint -= 1;
    return (*this);
}

Fixed   Fixed::operator --(int)
{
	Fixed tmp(*this);
	this->fixedPoint -= 1;
	return (tmp);
}

Fixed    &Fixed::min(Fixed &first, Fixed &second)
{
    if (first < second)
        return (first);
    return (second);
}

Fixed const   &Fixed::min(const Fixed &first, const Fixed &second)
{
    if (first.fixedPoint < second.fixedPoint)
        return (first);
    return (second);
}


Fixed    &Fixed::max(Fixed &first, Fixed &second)
{
    if (first > second)
        return (first);
    return (second);
}

Fixed const   &Fixed::max(const Fixed &first, const Fixed &second)
{
    if (first.fixedPoint > second.fixedPoint)
        return (first);
    return (second);
}


std::ostream& operator<<(std::ostream &COUT, Fixed const &rhs)
{
	COUT << rhs.toFloat();
	return COUT;
}