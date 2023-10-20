#include "./Bureaucrat.hpp"
#include "./ShrubberyCreationForm.hpp"

int main()
{
    try{
        
        Bureaucrat B1 = Bureaucrat("B1", 50);
        ShrubberyCreationForm PP = ShrubberyCreationForm("PP");
        PP.execute(B1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}