#include "./Bureaucrat.hpp"

int main()
{
    try{
        Bureaucrat B1 = Bureaucrat("Omar", 0);
        std::cout << B1.getName() << std::endl;
        std::cout << B1.getGrade() << std::endl;
        B1.decrement();
        std::cout << "======" << std::endl;
        std::cout << B1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}