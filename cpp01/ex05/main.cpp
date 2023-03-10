#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl H;
    if (ac != 2)
        return (std::cerr << "Usage: " << av[0] << " <level>:{DEBUG, INFO, WARNING, ERROR}" << std::endl, 0);
    H.complain(av[1]);
}