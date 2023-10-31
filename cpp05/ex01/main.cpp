#include "./Form.hpp"
#include "./Bureaucrat.hpp"

int main()
{
    try
    {
        
        Form F1 = Form("F1", 50, 50);
        std::cout << F1 << std::endl;
        
        F1.beSigned(Bureaucrat("B1", 49));

        Bureaucrat B1 = Bureaucrat("B1", 49);
        B1.signForm(F1);

        Bureaucrat B2 = Bureaucrat("B2", 51);
        B2.signForm(F1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}