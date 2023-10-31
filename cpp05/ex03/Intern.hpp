#pragma once

#include "./Bureaucrat.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

class	Intern {

    public:
        Intern();
        Intern(const Intern &obj);
        Intern &operator =(const Intern &rhs);
        ~Intern();
        AForm *makeForm(std::string type, std::string name);
};