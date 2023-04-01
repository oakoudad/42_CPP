#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
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
        std::cout << N[i]->getIdea(5) << std::endl;
        std::cout << "_________________" << std::endl;
    }

    for (int i = 0; i < 4; i++)
    {
        delete N[i];
        std::cout << "____" << std::endl;
    }
    return 0;
}