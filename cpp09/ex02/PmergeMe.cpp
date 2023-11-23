#include "PmergeMe.hpp"

bool checkArg(char *s)
{
    for (size_t i = 0; s[i] != '\0'; i++)
        if (!isdigit(s[i]))
            throw std::logic_error("Error");
    if (atoi(s) < 0)
        throw std::logic_error("Error");
    return true;
}
