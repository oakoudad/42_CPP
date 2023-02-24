#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"


class   PhoneBook {
    private:
        Contact Contactlist[8];
        int     index;
        int     inputsValidation(std::string str, std::string label);
        int     inputsValidatePhone(std::string str);
        void    shiftUp();
        int     isNumber(std::string nbr);

    public:
        PhoneBook();
        ~PhoneBook();
        void    addContact();
        void    searchContact(std::string str);
        void    searchContact();
};

#endif