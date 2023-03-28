#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

void p()
{
    Animal *j = new Animal[2];
    std::cout << "___" << std::endl;

    j[0] = Cat();
    std::cout << "___" << std::endl;
    j[1] = Cat();
    std::cout << "___" << std::endl;
    delete []j;
}

int main()
{
    {
        p();
    }
    while(1);
    return 0;
}