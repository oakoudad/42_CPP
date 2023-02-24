#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
    std::string type;
	PhoneBook *p = new (std::nothrow) PhoneBook();

    if (!p)
        return (0);
    do
    {
        std::cout << "Please type an of this commands (ADD, SEARCH or EXIT) : ";
        if (!std::getline(std::cin, type) || type == "EXIT")
        {
            delete p;
            exit(0);
        }
        else if (type == "ADD")
            p->addContact();
        else if (type == "SEARCH")
            p->searchContact();
        else if (type.empty())
            std::cerr << "\033[1;31m Empty command\033[0m\n";
        else
            std::cerr << "\033[1;31m Command not found\033[0m\n";
    }
    while(1);
    return (0);
}
