#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class   HumanB {
    private :
        Weapon      *gun;
        std::string name;

    public :
        HumanB( std::string the_name );
        ~HumanB();
        void    setWeapon(Weapon &the_gun);
        void    attack()const;

};

#endif