#include "Brain.hpp"

std::string intToString(int num) {
    std::string result = "";
    while (num > 0) {
        char digit = '0' + (num % 10);
        result = digit + result;
        num /= 10;
    }
    if (result == "")
        result = "0";
    return result;
}

Brain::Brain()
{
    for(int i = 0; i < 100; i++)
        this->ideas[i] = "Idea #" + intToString(i);
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

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return (this->ideas[index]);
    return ("(Brain) This index is not valid.");
}

Brain::~Brain()
{
    std::cout << "Brain destructor." << std::endl;
}