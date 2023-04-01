#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class   Animal {
    protected :
        std::string type;

    public :
        Animal();
        Animal( const Animal &obj );
        Animal &operator =(const Animal &rhs);
        
        virtual void        makeSound() const;
        std::string         getType() const;
        virtual std::string getIdea(int index) const;
        virtual ~Animal();
};


#endif