#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class   WrongAnimal {
    protected :
        std::string type;

    public :
        WrongAnimal();
        WrongAnimal( const WrongAnimal &obj );
        WrongAnimal &operator =(const WrongAnimal &rhs);
        
        virtual void    makeSound() const;
        std::string     getType() const;
        virtual ~WrongAnimal();
};


#endif