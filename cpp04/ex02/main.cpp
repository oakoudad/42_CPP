#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"


int main()
{
    Cat *c = new Cat();
    c->makeSound();
    return 0;
}