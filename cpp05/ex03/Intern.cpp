#include "./Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &obj)
{
    (void)obj;
}

Intern &Intern::operator =(const Intern &rhs)
{
    (void)rhs;
    return (*this);
}

AForm *Intern::makeForm(std::string type, std::string name)
{
    int i = ("robotomy request" == type) * 1 + ("shrubbery creation" == type) * 2 + ("presidential pardon" == type) * 3;

    switch(i)
    {
        case(1):
            return (new RobotomyRequestForm(name));
        case(2):
            return (new ShrubberyCreationForm(name));
        case(3):
            return (new PresidentialPardonForm(name));
        break;
    }
    std::cout << "Invalid Form" << std::endl;
    return(NULL);
}

Intern::~Intern(){}