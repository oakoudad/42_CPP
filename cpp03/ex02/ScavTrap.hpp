#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class   ScavTrap:public ClapTrap {

    public :
        ScavTrap();
        ScavTrap( const std::string name );
        ScavTrap( const ScavTrap &obj );
        ScavTrap &operator =(const ScavTrap &rhs);
        void    attack( const std::string& target );
        void    guardGate();

        ~ScavTrap();
};

# endif