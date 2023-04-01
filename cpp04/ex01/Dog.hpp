#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class   Dog: public Animal {
    private:
        Brain *brain;
    public :
        Dog();
        Dog( const Dog &obj );
        Dog &operator =(const Dog &rhs);
        
        void        makeSound() const;
        std::string getIdea(int index) const;
        ~Dog();
};


#endif