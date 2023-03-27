#include "Brain.hpp"

Brain::Brain()
{
    for(int i = 0; i < 100; i++)
    {
        this->ideas[i] = "Idea #" + std::to_string(i);
    }
    std::cout << "Brain default Constructor." << std::endl;
}

Brain   &Brain::operator =(const Brain &rhs)
{
    std::cout << "Brain Copy Assignment operator." << std::endl;
    if (&rhs != this)
        for(int i = 0; i < 100; i++)
            this->ideas[i] = rhs.ideas[i];
    return (*this);
}

Brain::Brain( const Brain &obj )
{
    std::cout << "Brain Copy Constructor." << std::endl;
    *this = obj;
}



Brain::~Brain()
{
    std::cout << "Brain destructor." << std::endl;
}