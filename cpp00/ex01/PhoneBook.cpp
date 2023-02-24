/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakoudad <oakoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:01:56 by oakoudad          #+#    #+#             */
/*   Updated: 2022/10/19 13:02:16 by oakoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int    PhoneBook::inputsValidation(std::string str, std::string label)
{
    int i;

    i = -1;
    if (str.empty())
    {
        std::cerr << "\033[1;31m The " + label + " input is requered.\033[0m\n";
        return (0);
    }
    while (str[++i])
    {
        if (!std::isspace(str[i]))
            break;
    }
    if (i == (int)str.length())
        return (0);
    return (1);
}

int    PhoneBook::inputsValidatePhone(std::string str)
{
    int i;

    i = -1;
    if (!inputsValidation(str, "Phone number"))
        return (0);
    while (str[++i])
    {
        if (!(std::isspace(str[i]) || std::isdigit(str[i]) || str[i] == '+'))
        {
            std::cerr << "\033[1;31m The phone format is wrong.\033[0m\n";
            return (0);
        }
    }
    return (1);
}

void    PhoneBook::shiftUp()
{
    for(int i = 1; i < 8; i++)
    {
        Contactlist[i-1].setFirstname(Contactlist[i].getFirstname());
        Contactlist[i-1].setLastname(Contactlist[i].getLastname());
        Contactlist[i-1].setNickname(Contactlist[i].getNickname());
        Contactlist[i-1].setPhoneNumber(Contactlist[i].getPhoneNumber());
        Contactlist[i-1].setDarkestSecret(Contactlist[i].getDarkestSecret());
    }
}

void    PhoneBook::addContact()
{
    std::string     fname;
    std::string     lname;
    std::string     nname;
    std::string     phone;
    std::string     dsecret;

    do
    {
        std::cout << "Please, enter your First name: ";
        if (!std::getline(std::cin, fname))
            exit(0);
    }
    while(inputsValidation(fname, "First name") == 0);

    do
    {
        std::cout << "Please, enter your Last name: ";
        if (!std::getline(std::cin, lname))
            exit(0);
    }
    while(inputsValidation(lname, "Last name") == 0);

    do
    {
        std::cout << "Please, enter your Nick name: ";
        if (!std::getline(std::cin, nname))
            exit(0);
    }
    while(inputsValidation(nname, "Nick name") == 0);

    do
    {
        std::cout << "Please, enter your Phone number: ";
        if (!std::getline(std::cin, phone))
            exit(0);
    }
    while(inputsValidatePhone(phone) == 0);

    do
    {
        std::cout << "Please, enter your Darkest secret: ";
        if (!std::getline(std::cin, dsecret))
            exit(0);
    }
    while(inputsValidation(dsecret, "Darkest secret") == 0);
    if (index == 8)
    {
        shiftUp();
        Contactlist[7].setFirstname(fname);
        Contactlist[7].setLastname(lname);
        Contactlist[7].setNickname(nname);
        Contactlist[7].setPhoneNumber(phone);
        Contactlist[7].setDarkestSecret(dsecret);
    }
    else
    {
        Contactlist[index].setFirstname(fname);
        Contactlist[index].setLastname(lname);
        Contactlist[index].setNickname(nname);
        Contactlist[index].setPhoneNumber(phone);
        Contactlist[index++].setDarkestSecret(dsecret);
    }
    std::cout << "\033[1;32mContact add with success\033[0m\n";
}

std::string designStr(std::string str)
{
    std::string result;

    if (str.length() == 10)
        return (str);
    else if (str.length() > 10)
        return (str.substr(0, 9) + '.');
    result = "";
    for (int i = 0; i < 10 - (int)str.length(); i++)
        result += " ";
    return (result + str);
}

void    PhoneBook::searchContact(std::string str)
{
    for(int i = 0; i < index; i++)
    {
        if (std::to_string(i) == str)
        {
            std::cout << "First name     : " + Contactlist[i].getFirstname() + "\n";
            std::cout << "Last name      : " + Contactlist[i].getLastname() + "\n";
            std::cout << "Nick name      : " + Contactlist[i].getNickname() + "\n";
            std::cout << "Phone number   : " + Contactlist[i].getPhoneNumber() + "\n";
            std::cout << "Darkest secret : " + Contactlist[i].getDarkestSecret() + "\n";
            return ;
        }
    }
    std::cerr << "\033[1;31m This record is empty\033[1;0m\n";
}

int    PhoneBook::isNumber(std::string nbr)
{
    for (int i = 0; i < (int)nbr.length(); i++) {
        if (std::isdigit(nbr[i]) == 0)
            return 0;
    }
    return 1;
}

void    PhoneBook::searchContact()
{
    std::string code;
    int         status = 1;
    std::cout << "     Index|First name| Last name|  nickname\n";
    for(int i = 0; i < index; i++)
    {
        std::cout << "         " + std::to_string(i) + "|";
        std::cout << designStr(Contactlist[i].getFirstname()) + "|";
        std::cout << designStr(Contactlist[i].getLastname()) + "|";
        std::cout << designStr(Contactlist[i].getNickname()) + "\n";
    }

    do
    {
        std::cout << "Enter an index : ";
        if (!std::getline(std::cin, code))
            exit(0);
        if (isNumber(code) == 0 || (std::stol(code) < 0 || std::stol(code) >= 8))
            std::cerr << "\033[1;31m The index must be between 0 to 7\033[0m\n";
        else
        {
            searchContact(code);
            status = 0;
        }
    } while (status);
    
}

PhoneBook::PhoneBook()
{
    index = 0;
}

PhoneBook::~PhoneBook()
{
    std::cout << "PhoneBook distracted" << std::endl;
}
