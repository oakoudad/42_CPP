#include "Span.hpp"

Span::Span()
{
    this->N = 42;
    C.reserve(this->N);
}

Span::Span(unsigned int N)
{
    this->N = N;
    C.reserve(this->N);
}

void Span::addNumber(int node)
{
    if (this->N < C.size() + 1)
        throw std::logic_error("OUT OF RANGE");
	this->C.push_back(node);
}

int Span::shortestSpan() const
{
    std::vector<int> tmp = this->C;
    std::sort (tmp.begin(), tmp.end());

    if (tmp.size() < 2)
        throw std::logic_error("NO SPACE LEFT");
    int n = 0;
    for (unsigned int i = 0; i < tmp.size() - 1; i++)
    {
        if (n == 0)
            n = tmp[i + 1] - tmp[i];
        else if (n > tmp[i + 1] - tmp[i])
            n = tmp[i + 1] - tmp[i];
    }
    return (n);
}

int Span::longestSpan() const
{
    std::vector<int> tmp = this->C;
    std::sort (tmp.begin(), tmp.end());
    if (tmp.size() < 2)
        throw std::logic_error("NO SPACE LEFT");
    return (tmp[tmp.size() - 1] - tmp[0]);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (this->N < C.size() + std::distance(begin, end))
        throw std::logic_error("OUT OF RANGE");
    this->C.insert(this->C.end(), begin, end);
}
const std::vector<int> &Span::getContainer() const{return (this->C);}

Span::~Span(){}
