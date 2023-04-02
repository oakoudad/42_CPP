#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

void test(){
    
}
int main()
{
    const Animal *N[10];

    std::cout << "____" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        if (i % 2)
            N[i] = new Dog();
        else
            N[i] = new Cat();
        N[i]->makeSound();
        std::cout << N[i]->getIdea(i) << std::endl;
        std::cout << "_________________" << std::endl;
    }

    for (int i = 0; i < 10; i++)
    {
        delete N[i];
        std::cout << "____" << std::endl;
    }

    std::cout << "____________" << std::endl;

    const Animal* a = new Dog();
    const Animal* b = new Cat();
    delete a;
    delete b;

    return 0;
}