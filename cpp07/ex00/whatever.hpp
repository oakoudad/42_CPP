#pragma once

#include <iostream>

template <typename T>
void    swap(T &A, T &B)
{
    T tmp = A;
    A = B;
    B = tmp;
}

template <typename T>
T    min(T A, T B)
{
    return (A < B ? A : B);
}

template <typename T>
T    max(T A, T B)
{
    return (A > B ? A : B);
}