#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class   Weapon {
    private :
        std::string type;

    public :
        Weapon();
        Weapon(std::string tye);
        ~Weapon();
        const std::string  &getType( void )const;
        void                setType( std::string new_type );

};


#endif