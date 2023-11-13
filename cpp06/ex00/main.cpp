#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
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
