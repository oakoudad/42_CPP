#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class   AAnimal {
    protected :
        std::string type;

    public :
        AAnimal();
        AAnimal(const AAnimal& obj);
        AAnimal& operator=(const AAnimal &rhs);

        virtual void        makeSound() const   = 0;
        virtual std::string getType()   const   = 0;

        virtual ~AAnimal();
};


#endif