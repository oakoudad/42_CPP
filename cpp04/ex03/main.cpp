
#include "Ice.hpp"
#include "Character.hpp"

int main()
{
    AMateria *p = new Ice();
    Ice *p2 = new Ice();
    std::cout << p->getType() << std::endl;

    ICharacter* me = new Character("me");

    p->use(me);
    std::cout << p2->getType() << std::endl;
}