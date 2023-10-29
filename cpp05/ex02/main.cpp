#include "./Bureaucrat.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

int main()
{

    PresidentialPardonForm PPF = PresidentialPardonForm("PPF");
    Bureaucrat B1 = Bureaucrat("B1", 6);// 5
    
    std::cout << PPF;
    std::cout << B1 << std::endl << std::endl;

    B1.signForm(PPF);
    B1.executeForm(PPF);

    std::cout << std::endl << std::endl << std::endl << std::endl;

    ShrubberyCreationForm SCF = ShrubberyCreationForm("SCF");
    std::cout << SCF;

    Bureaucrat B2 = Bureaucrat("B2", 150);// 137
    
    std::cout << B2 << std::endl << std::endl;

    B2.signForm(SCF);
    B2.executeForm(SCF);

    std::cout << std::endl << std::endl << std::endl << std::endl;

    RobotomyRequestForm RRF = RobotomyRequestForm("RRF");
    std::cout << RRF;

    Bureaucrat B3 = Bureaucrat("B3", 50);// 45
    
    std::cout << B3 << std::endl << std::endl;

    B3.signForm(RRF);
    B3.executeForm(RRF);
        
    
    return (0);
}