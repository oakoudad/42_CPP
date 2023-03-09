#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class   HumanA {
    private :
        Weapon      &gun;
        std::string name;

    public :
        HumanA( std::string the_name, Weapon &the_gun);
        HumanA();
        ~HumanA();
        void    attack()const;

};

#endif