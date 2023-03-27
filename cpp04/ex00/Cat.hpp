#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class   Cat: public Animal {
    public :
        Cat();
        Cat( const Cat &obj );
        Cat &operator =(const Cat &rhs);
        
        void        makeSound() const;
        ~Cat();
};


#endif