#include "./Intern.hpp"
#include "./AForm.hpp"


int main()
{
    Intern someRandomIntern;

    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << *rrf << std::endl;
    delete rrf;

    AForm* scf = someRandomIntern.makeForm("shrubbery creation", "SH");
    std::cout << *scf << std::endl;
    delete scf;

    AForm* ppf = someRandomIntern.makeForm("presidential pardon", "PP");
    std::cout << *ppf << std::endl;
    delete ppf;

    return (0);
}