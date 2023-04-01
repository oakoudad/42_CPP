
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"


int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp = src->createMateria("ice");
    me->equip(tmp);
    AMateria* tmp2 = src->createMateria("cure");
    me->equip(tmp2);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete tmp;
    delete tmp2;
    delete bob;
    delete me;
    delete src;
    return 0;
}