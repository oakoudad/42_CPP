#include "./Bureaucrat.hpp"

int main()
{
    Bureaucrat B1 = Bureaucrat();
    std::cout << B1.getName() << std::endl;
    std::cout << B1.getGrade() << std::endl;
    B1.increment();
    std::cout << "======" << std::endl;
    std::cout << B1.getGrade() << std::endl;
}