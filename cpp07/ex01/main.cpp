#include "iter.hpp"

void putnbr(int n, char c)
{
    std::cout << n << std::endl;
}

void putstr(std::string str)
{
    std::cout << str << std::endl;
}

int main( void )
{
    int int_arr[] = {10, 20, 30, 42, 1337};
    ::iter(&int_arr, sizeof(int_arr) / sizeof(int), putnbr);

    std::cout << std::endl << std::endl;

    std::string str_arr[] = {"1337.ma", "Mediaplus.ma"};
    ::iter(&str_arr, sizeof(str_arr) / sizeof(std::string), putstr);
}