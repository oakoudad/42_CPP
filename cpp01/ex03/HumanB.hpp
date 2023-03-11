#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class   HumanB {
    private :
        Weapon      *gun;
        std::string name;

    public :
        HumanB( std::string name );
        ~HumanB();
        void    setWeapon(Weapon &gun);
        void    attack()const;

};

#endif