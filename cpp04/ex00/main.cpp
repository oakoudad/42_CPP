#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void p()
{
    const Animal* j = new Dog();

    std::cout << j->getType() << " " << std::endl;
   
    j->makeSound();
    
    delete j;
}

int main()
{
    p();
    std::cout << "_________" << std::endl;
    const WrongAnimal* j = new WrongCat();

    std::cout << j->getType() << " " << std::endl;
   
    j->makeSound();
    
    delete (j);
    while(1);
    return 0;
}