#ifndef ZOMBIE2_HPP
# define ZOMBIE2_HPP

#include <iostream>

class   Zombie {
    private :
        std::string name;

    public :
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void    announce( void );
        void    setName( std::string name );

};

Zombie* zombieHorde( int N, std::string name );

#endif