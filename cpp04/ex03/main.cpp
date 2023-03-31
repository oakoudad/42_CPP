
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
    ICharacter* me = new Character();
    ICharacter* bob = new Character("bob");

    std::cout << me->getName() << std::endl;


    me->equip(new Cure());
    
    me->use(0, *bob);
    delete bob;
    delete me;
}