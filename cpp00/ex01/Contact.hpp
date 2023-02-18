#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class   Contact {
    private :
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    
    public :
        void    setFirstname(std::string fname);
        void    setLastname(std::string lname);
        void    setNickname(std::string nickname);
        void    setPhoneNumber(std::string phone_number);
        void    setDarkestSecret(std::string phone_number);
        void    getFirstname(std::string fname);
        void    getLastname(std::string lname);
        void    getNickname(std::string nickname);
        void    getPhoneNumber(std::string phone_number);
        void    getDarkestSecret(std::string phone_number);
        
};

#endif