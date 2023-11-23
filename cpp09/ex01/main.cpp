#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cerr << "usage: ./RPN [numbers, operators]" << std::endl, 0);
    try
    {
        RPN rpn = RPN(av[1]);
    }
    catch (std::exception &e){std::cout << e.what() << std::endl;}
    return (0);
}