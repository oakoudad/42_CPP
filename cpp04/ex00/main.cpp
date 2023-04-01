#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int main()
{
    const Animal* j = new Dog();

    std::cout << j->getType() << " " << std::endl;
   
    j->makeSound();
    
    delete j;

    std::cout << "_________" << std::endl;
    const WrongAnimal* j = new WrongCat();

    std::cout << j->getType() << " " << std::endl;
   
    j->makeSound();
    
    delete (j);
    return 0;
}