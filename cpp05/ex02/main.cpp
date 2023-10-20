#include "./Bureaucrat.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include <ctime>

int main()
{
    try{
        RobotomyRequestForm RRF = RobotomyRequestForm("RRF");
        Bureaucrat B = Bureaucrat("B", 45);

        RRF.beSigned(B);
        RRF.execute(B);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}