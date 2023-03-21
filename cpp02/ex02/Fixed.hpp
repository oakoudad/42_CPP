#ifndef FIXED02_HPP
# define FIXED02_HPP

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
        Fixed               &operator =(const Fixed &rhs);
        Fixed               operator  *(const Fixed &rhs);
        Fixed               operator  /(const Fixed &rhs);
        Fixed               operator  +(const Fixed &rhs);
        Fixed               operator  -(const Fixed &rhs);
        bool                operator  >(const Fixed &rhs);
        bool                operator  >=(const Fixed &rhs);
        bool                operator  <(const Fixed &rhs);
        bool                operator  <=(const Fixed &rhs);
        bool                operator  ==(const Fixed &rhs);
        bool                operator  !=(const Fixed &rhs);

        Fixed               &operator++(void);
        Fixed               operator++(int);
        Fixed               &operator--(void);
        Fixed               operator--(int);

        int                 getRawBits(void) const;
		void                setRawBits(int const raw);
        float               toFloat( void ) const;
        int                 toInt( void )   const;

        
        static Fixed        &min(Fixed &first, Fixed &second);
        static Fixed const  &min(const Fixed &first, const Fixed &second);
        static Fixed        &max(Fixed &first, Fixed &second);
        static Fixed const  &max(const Fixed &first, const Fixed &second);

        ~Fixed();

};

std::ostream& operator<<(std::ostream &COUT, Fixed const & rhs);
#endif