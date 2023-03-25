#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class   ClapTrap {
    private :
        std::string     name;
        unsigned int    hit;
        unsigned int    energy;
        unsigned int    damage;
    public :
        ClapTrap();
        ClapTrap( const std::string name );
        ClapTrap( const ClapTrap &obj );
        ClapTrap &operator =(const ClapTrap &rhs);

        void    attack( const std::string& target );
        void    takeDamage( unsigned int amoun );
        void    beRepaired( unsigned int amount );
        ~ClapTrap();
};

#endif