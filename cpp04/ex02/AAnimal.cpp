#include "AAnimal.hpp"

AAnimal::AAnimal(){
    std::cout << "AAnimal default Constructor." << std::endl;
}

AAnimal::AAnimal(const AAnimal& obj){
    std::cout << "AAnimal Copy Constructor." << std::endl;
    (void)obj;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs){
    std::cout << "AAnimal Copy Assignment operator." << std::endl;
    (void)rhs;
    return (*this);
}

AAnimal::~AAnimal(){
    std::cout << "AAnimal destructor." << std::endl;
}