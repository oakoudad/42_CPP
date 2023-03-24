#include "ScavTrap.hpp"

std::string nameColor2(std::string n)
{
    return "\033[1;29m" + n + "\033[0m";
}

void    values2( unsigned int h, unsigned int e, unsigned int d )
{
    std::cout << "\033[1;30m// Hit points    : " << h << std::endl;
    std::cout << "// Energy points : " << e << std::endl;
    std::cout << "// Attack damage : " << d << "\033[0m" << std::endl << std::endl;
}

ScavTrap::ScavTrap()
{
    name    = "Default name";
    hit     = 100;
    energy  = 100;
    damage  = 30;
    std::cout << nameColor2(name) << " Default constructor (ScavTrap)." << std::endl << std::endl;
}

ScavTrap::ScavTrap( const std::string name )
{
    this->name  = name;
    hit         = 100;
    energy      = 100;
    damage      = 30;
    std::cout << nameColor2(name) << " Parameterized constructor (ScavTrap)." << std::endl << std::endl;
}

ScavTrap::ScavTrap( const ClapTrap &obj )
{
    std::cout << nameColor2(name) << " Copy constructor (ScavTrap)." << std::endl << std::endl;
    *this = obj;
}

ScavTrap   &ScavTrap::operator =(const ScavTrap &rhs)
{
    std::cout << nameColor2(name) << " Copy Assignment operator (ScavTrap)." << std::endl << std::endl;
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
        std::cout << "ScavTrap " << nameColor2(name) << " attacks " << target << ", causing " << damage << " points of damage!" << std::endl;
        values2(hit, energy, damage);
    }
    else
    {
        std::cout << nameColor2(name) << " can’t do anything." << std::endl;
        values2(hit, energy, damage);
    }
}

ScavTrap::~ScavTrap()
{
    std::cout << std::endl << nameColor2(name) << " Destructor (ScavTrap)." << std::endl;
}