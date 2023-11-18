#include "Span.hpp"

int main()
{
    // basic test
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    try
    {
        sp.addNumber(11);
    }catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "---------------------" << std::endl;

    // More than 10000 numbers
    Span a(20000);
    for(int i = 0; i < 20000; i++)
        a.addNumber(i);
    std::cout << a.shortestSpan() << std::endl;
    std::cout << a.longestSpan() << std::endl;

    std::cout << "---------------------" << std::endl;

    // insert range of iterators
    Span b(5);


    std::vector<int> v = sp.getContainer();
    b.addNumbers(v.begin(), v.end());
    std::cout << b.shortestSpan() << std::endl;
    std::cout << b.longestSpan() << std::endl;
    try
    {
        b.addNumbers(v.begin(), v.end());
    }catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}