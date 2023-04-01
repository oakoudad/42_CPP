#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class   Cat: public Animal {
    private:
        Brain *brain;

    public :
        Cat();
        Cat( const Cat &obj );
        Cat &operator =(const Cat &rhs);
        
        std::string getIdea(int index) const;
        void        makeSound() const;
        ~Cat();
};


#endif