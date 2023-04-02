#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

void    test00()
{
    AAnimal *dog = new Dog();
    dog->makeSound();

    Cat *cat = new Cat();
    cat->makeSound();

    delete cat;
    delete dog;
    std::cout << "____________________________________" << std::endl;
}

void test01()
{
    Cat *cat = new Cat();
    Cat *cat2 = new Cat();

    cat2->setIdea(0, "Good idea");
    std::cout << "-> " << cat2->getIdea(0) << std::endl;
    *cat = *cat2;
    std::cout << "-> " << cat->getIdea(0) << std::endl;
    delete cat;
    delete cat2;
}
int main()
{
    test00();
    test01();
    return 0;
}