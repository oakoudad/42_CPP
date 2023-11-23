#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cerr << "Error: could not open file." << std::endl, 0);
    try
    {
        BitcoinExchange exchange = BitcoinExchange();
        exchange.print(av[1]);
    }
    catch (std::exception &e){std::cout << e.what() << std::endl;}
    return (0);
}