#include "./Form.hpp"
#include "./Bureaucrat.hpp"

int main()
{
    try{
        Form F1 = Form("Form", 50, 50);
        std::cout << F1 << std::endl;
        Bureaucrat B1 = Bureaucrat("Bureaucrat", 51);
        B1.signForm(F1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}