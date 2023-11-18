#pragma once

#include <iterator>
#include <iostream>

template <typename T>
void    easyfind(T &C, int n)
{
    for (typename T::iterator it = C.begin(); it != C.end(); it++){
        if (*it == n) return (std::cout << "the " << *it << " exest in Container" << std::endl, (void)n);
    }
    throw std::logic_error("Occurrence not faund");
}