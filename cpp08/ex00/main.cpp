#include "easyfind.hpp"
#include <vector>
#include <deque>

int main()
{
    std::vector<int> v(10);
    for (size_t i = 0; i < 10; i++)
        v[i] = i*2;
    easyfind(v, 4);
    easyfind(v, 18);
    easyfind(v, 12);
    try{easyfind(v, 1);}catch (const std::exception &e){std::cerr << e.what() << '\n';}

    std::deque<int> d(10);
    for (size_t i = 0; i < 10; i++)
        d[i] = i*2;
    easyfind(d, 4);
    easyfind(d, 18);
    easyfind(d, 12);
}