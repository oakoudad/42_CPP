#include "./Bureaucrat.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

int main()
{
    try{
        PresidentialPardonForm RRF = PresidentialPardonForm("RRF");
        Bureaucrat B = Bureaucrat("B", 4);
        // B.signForm(RRF);
        B.executeForm(RRF);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    // try{
    //     PresidentialPardonForm RRF = PresidentialPardonForm("RRF");
    //     Bureaucrat B = Bureaucrat("B", 10);
    //     B.executeForm(RRF);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
    return (0);
}