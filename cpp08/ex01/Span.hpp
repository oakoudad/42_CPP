#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
    private:
        unsigned int N;
        std::vector<int> C;

    public:
        Span();
        Span(const Span &span);
        Span(unsigned int N);
        Span & operator=(const Span &rhs);
        ~Span();

        void    addNumber(int node);
        int     shortestSpan() const;
        int     longestSpan() const;
        void    addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        const std::vector<int> &getContainer() const;
        

};