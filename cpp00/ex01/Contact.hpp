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
        Contact();
        Contact(std::string firstname, std::string lastname);
        ~Contact();
        void                setFirstname(std::string firstname);
        void                setLastname(std::string lastname);
        void                setNickname(std::string nickname);
        void                setPhoneNumber(std::string phone_number);
        void                setDarkestSecret(std::string phone_number);
        const std::string   getFirstname()const;
        const std::string   getLastname()const;
        const std::string   getNickname()const;
        const std::string   getPhoneNumber()const;
        const std::string   getDarkestSecret()const;
};

#endif