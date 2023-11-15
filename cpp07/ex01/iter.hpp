#pragma once

#include <iostream>

template <typename A, typename F> 
void    iter(A *arr, size_t len, F fun)
{
    if (!fun)
        throw std::logic_error("Invalid function");
    for (size_t i = 0; i < len; i++)
        fun((*arr)[i]);
}