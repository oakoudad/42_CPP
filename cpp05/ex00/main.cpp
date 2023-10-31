#include "./Bureaucrat.hpp"

int main()
{
    try{
        Bureaucrat B1 = Bureaucrat("B1", 1);
        std::cout << "name: " << B1.getName() << ", Grade: " << B1.getGrade() << std::endl;
        B1.decrement();
        std::cout << B1 << std::endl;
        B1.increment();
        std::cout << B1 << std::endl;
        std::cout << "____________________ COPY CONSTRUCTOR ____________________" << std::endl;
        Bureaucrat B2 = Bureaucrat(B1);
        std::cout << B2 << std::endl;
        std::cout << "____________________ COPY ASSIGNMENT _____________________" << std::endl;
        Bureaucrat B3 = B2;
        std::cout << B3 << std::endl << std::endl;

        Bureaucrat *B4 = new Bureaucrat();
        std::cout << (*B4) << std::endl << std::endl;
        delete B4;
        std::cout << "____________________ EXCEPTIONS __________________________" << std::endl;
        B1.increment();
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}