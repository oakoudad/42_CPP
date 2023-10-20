#include "./Bureaucrat.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include <ctime>

int main()
{
    try{
        PresidentialPardonForm RRF = PresidentialPardonForm("RRF");
        Bureaucrat B = Bureaucrat("B", 5);

        RRF.beSigned(B);
        RRF.execute(B);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}