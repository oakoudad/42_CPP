#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class   Dog: public AAnimal {
    private:
        Brain *brain;

    public :
        Dog();
        Dog( const Dog &obj );
        Dog &operator =(const Dog &rhs);

        std::string getType() const;
        void        makeSound() const;
        std::string getIdea(int index) const;
        void        setIdea(int index, const std::string s);
        ~Dog();
};


#endif