#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    name    = "Default name";
    hit     = 100;
    energy  = 100;
    damage  = 30;
    std::cout << nameColor(name) << " Default constructor (FragTrap)." << std::endl << std::endl;
}

FragTrap::FragTrap( const std::string name )
{
    this->name  = name;
    hit         = 100;
    energy      = 100;
    damage      = 30;
    std::cout << nameColor(name) << " Parameterized constructor (FragTrap)." << std::endl << std::endl;
}

FragTrap::FragTrap( const FragTrap &obj )
{
    std::cout << nameColor(name) << " Copy constructor (FragTrap)." << std::endl << std::endl;
    *this = obj;
}

FragTrap   &FragTrap::operator =(const FragTrap &rhs)
{
    std::cout << nameColor(name) << " Copy Assignment operator (FragTrap)." << std::endl << std::endl;
    if (&rhs != this)
    {
        this->name      = rhs.name;
        this->hit       = rhs.hit;
        this->energy    = rhs.energy;
        this->damage    = rhs.damage;
    }
    return (*this);
}

void    FragTrap::highFivesGuys()
{
    std::cout << "The fragTrap " << name << " says: High Fives Guys!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << std::endl << nameColor(name) << " Destructor (FragTrap)." << std::endl;
}