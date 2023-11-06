#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <sstream>


int main(int argc, char **argv)
{
    std::cout << std::endl << std::fixed 
        << argv[1] << std::endl 
        << std::to_string(std::numeric_limits<double>::lowest()).c_str()
    << std::endl << std::endl;
    try
    {
        if (argc != 2 || !argv[1][0])
            return (std::cerr << argv[0] << ":usage error: ./convert <literal>" << std::endl, 0);
        ScalarConverter::convert(argv[1]);
    }
    catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
