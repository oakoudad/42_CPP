#include "ClapTrap.hpp"

std::string nameColor(std::string n)
{
    return "\033[1;29m" + n + "\033[0m";
}

void    values( unsigned int h, unsigned int e, unsigned int d )
{
    std::cout << "\033[1;30m// Hit points    : " << h << std::endl;
    std::cout << "// Energy points : " << e << std::endl;
    std::cout << "// Attack damage : " << d << "\033[0m" << std::endl;
}

ClapTrap::ClapTrap()
{
    name    = "";
    hit     = 10;
    energy  = 10;
    damage  = 0;
    std::cout << "Default constructor (ClapTrap)." << std::endl;
}

ClapTrap::ClapTrap( const std::string name )
{
    this->name  = name;
    hit         = 10;
    energy      = 10;
    damage      = 0;
    std::cout << "Parameterized constructor (ClapTrap)." << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &obj )
{
    std::cout << "Copy constructor (ClapTrap)." << std::endl;
    *this = obj;
}

ClapTrap   &ClapTrap::operator =(const ClapTrap &rhs)
{
    std::cout << "Copy Assignment operator (ClapTrap)." << std::endl;
    if (&rhs != this)
    {
        this->name      = rhs.name;
        this->hit       = rhs.hit;
        this->energy    = rhs.energy;
        this->damage    = rhs.damage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if ((int)energy && (int)hit)
    {
        energy--;
        std::cout << "ClapTrap " << nameColor(name) << " attacks " << target << ", causing " << damage << " points of damage!" << std::endl;
        values(hit, energy, damage);
    }
    else
    {
        std::cout << nameColor(name) << " can’t do anything." << std::endl;
        values(hit, energy, damage);
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit == 0 || (int)(hit - amount) <= 0)
    {
        hit = 0;
        std::cout << nameColor(name) << " can’t do anything." << std::endl;
        values(hit, energy, damage);
        return ;
    }
    if (hit - amount > 0)
    {
        hit -= amount;
        std::cout << nameColor(name) << " take damage." << std::endl;
        values(hit, energy, damage);
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hit == 0 || energy == 0)
    {
        std::cout << nameColor(name) << " can’t do anything." << std::endl;
        values(hit, energy, damage);
        return ;
    }
    if (energy)
    {
        energy--;
        hit += amount;
        std::cout << nameColor(name) << "'s hit repaired." << std::endl;
        values(hit, energy, damage);
    }
}


ClapTrap::~ClapTrap(){
    std::cout << nameColor(name) << " Destructor (ClapTrap)." << std::endl;
}