#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class   Cat: public AAnimal {
    private:
        Brain *brain;

    public :
        Cat();
        Cat( const Cat &obj );
        Cat &operator =(const Cat &rhs);

        std::string getType() const;
        void        makeSound() const;
        std::string getIdea(int index) const;
        void        setIdea(int index, const std::string s);
        ~Cat();
};


#endif