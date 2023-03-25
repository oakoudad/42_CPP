#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    name    = "Default name";
    hit     = 100;
    energy  = 100;
    damage  = 30;
    std::cout << nameColor(name) << " Default constructor (ScavTrap)." << std::endl << std::endl;
}

ScavTrap::ScavTrap( const std::string name )
{
    this->name  = name;
    hit         = 100;
    energy      = 100;
    damage      = 30;
    std::cout << nameColor(name) << " Parameterized constructor (ScavTrap)." << std::endl << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &obj )
{
    std::cout << nameColor(name) << " Copy constructor (ScavTrap)." << std::endl << std::endl;
    *this = obj;
}

ScavTrap   &ScavTrap::operator =(const ScavTrap &rhs)
{
    std::cout << nameColor(name) << " Copy Assignment operator (ScavTrap)." << std::endl << std::endl;
    if (&rhs != this)
    {
        this->name      = rhs.name;
        this->hit       = rhs.hit;
        this->energy    = rhs.energy;
        this->damage    = rhs.damage;
    }
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if ((int)energy && (int)hit)
    {
        energy--;
        std::cout << "ScavTrap " << nameColor(name) << " attacks " << target << ", causing " << damage << " points of damage!" << std::endl;
        values(hit, energy, damage);
    }
    else
    {
        std::cout << nameColor(name) << " can’t do anything." << std::endl;
        values(hit, energy, damage);
    }
}

void    ScavTrap::guardGate()
{
    std::cout << "The " << nameColor(name) << " in Gate keeper mode." << std::endl << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << std::endl << nameColor(name) << " Destructor (ScavTrap)." << std::endl;
}