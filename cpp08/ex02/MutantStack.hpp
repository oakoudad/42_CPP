#pragma once

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
    public:
        MutantStack(){}

        MutantStack(const MutantStack &cpy){
            this = cpy;
        }

        MutantStack &operator=(const MutantStack &rhs)
        {
            this = rhs;
            return (*this);
        }

        ~MutantStack(){}

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        iterator begin()
        {
            return (std::stack<T>::c.begin());
        }

        iterator end()
        {
            return (std::stack<T>::c.end());
        }

        const_iterator cbegin() const
        {
            return (std::stack<T>::c.cbegin());
        }

        const_iterator cend() const
        {
            return (std::stack<T>::c.cend());
        }

};