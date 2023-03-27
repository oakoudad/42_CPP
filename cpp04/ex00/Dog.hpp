#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class   Dog: public Animal {
    public :
        Dog();
        Dog( const Dog &obj );
        Dog &operator =(const Dog &rhs);
        
        void        makeSound() const;
        ~Dog();
};


#endif