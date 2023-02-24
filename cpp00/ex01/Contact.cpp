
#include "Contact.hpp"

void        Contact::setFirstname(std::string str)
{
    firstname = str;
}

const       std::string Contact::getFirstname()const
{
    return (firstname);
}

void        Contact::setLastname(std::string str)
{
    lastname = str;
}

const       std::string Contact::getLastname()const
{
    return (lastname);
}

void        Contact::setNickname(std::string str)
{
    nickname = str;
}

const       std::string Contact::getNickname()const
{
    return (nickname);
}

void        Contact::setPhoneNumber(std::string str)
{
    phone_number = str;
}

const       std::string Contact::getPhoneNumber()const
{
    return (phone_number);
}

void        Contact::setDarkestSecret(std::string str)
{
    darkest_secret = str;
}

const       std::string Contact::getDarkestSecret()const
{
    return (darkest_secret);
}

Contact::Contact()
{}

Contact::Contact(std::string fname, std::string lname)
{
    std::cout << "Contact init with args" << std::endl;
    firstname = fname;
    lastname = lname;
}

Contact::~Contact()
{}