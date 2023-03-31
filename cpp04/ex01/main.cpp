#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

void test01()
{
    const Animal *N[4];

    std::cout << "____" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (i % 2)
            N[i] = new Dog();
        else
            N[i] = new Cat();
        N[i]->makeSound();
        std::cout << "_________________" << std::endl;
    }

    for (int i = 0; i < 4; i++)
    {
        delete N[i];
        std::cout << "____" << std::endl;
    }
    
}

int main()
{
    test01();
    {
        Cat c;

        Cat d = c;
    }
    while(1);
    return 0;
}