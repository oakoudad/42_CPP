#ifndef FIXED01_HPP
# define FIXED01_HPP

#include <iostream>
#include <cmath>

class   Fixed {
    private :
        int                 fixedPoint;
        static const int    fractionalBits = 8;

    public :
        Fixed();
        Fixed( const Fixed &obj );
        Fixed( const int nbr );
        Fixed( const float nbr );
        Fixed &operator =(const Fixed &rhs);
        int	getRawBits(void) const;
		void setRawBits(int const raw);

        float   toFloat( void ) const;
        int     toInt( void )   const;
        ~Fixed();

};

std::ostream& operator<<(std::ostream &COUT, Fixed const & rhs);
#endif