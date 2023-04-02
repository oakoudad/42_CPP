#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void test00()
{
    std::cout << "_________ TEST 00 START _________" << std::endl;
    const Animal* dog = new Dog();

    std::cout << dog->getType() << std::endl;
   
    dog->makeSound();
    
    delete dog;
    std::cout << "_________ TEST 00 END _________" << std::endl << std::endl;
}

void test01()
{
    std::cout << "_________ TEST 01 START _________" << std::endl;
    const Cat* cat = new Cat();

    std::cout << cat->getType() << std::endl;
   
    cat->makeSound();
    
    delete cat;
    std::cout << "_________ TEST 01 END _________" << std::endl << std::endl;
}

void test02()
{
    std::cout << "_________ TEST 02 START _________" << std::endl;
    const Animal* animal = new Animal();

    std::cout << animal->getType() << std::endl;
   
    animal->makeSound();
    
    delete (animal);
    std::cout << "_________ TEST 02 END _________" << std::endl << std::endl;
}

void test03()
{
    std::cout << "_________ TEST 02 START _________" << std::endl;
    const WrongAnimal* wrong = new WrongCat();

    std::cout << wrong->getType() << std::endl;
   
    wrong->makeSound();
    
    delete (wrong);
    std::cout << "_________ TEST 02 END _________" << std::endl << std::endl;
}

int main()
{
    test00();
    test01();
    test02();
    test03();

    return 0;
}