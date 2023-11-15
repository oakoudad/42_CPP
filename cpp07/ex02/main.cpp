#include "Array.hpp"
#include <vector>

template <typename T>
void printer(const Array<T> &arr, const std::string &name)
{
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << name << "[" << i << "] = '" << arr[i] << "'" << std::endl;
    std::cout << "> " << "Size: " << arr.size() << std::endl << std::endl;
}

void tests()
{
    Array<std::string> N1(5);

    for (size_t i = 0; i < N1.size(); i++)
        N1[i] = "Hello "+std::to_string(i);
    printer(N1, "N1");


    Array<std::string> N2(N1);
    printer(N2, "N2");


    Array<std::string> N3;
    N3 = N2;
    printer(N3, "N3");

    try
    {
        N3[10] = "Hello";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    const Array<std::string> N4(N3);
    printer(N4, "N4");
}

int main()
{
    tests();
    
    std::cout << "Leaks:" << std::endl;
    system("leaks Array | grep 'Process '");
    return (0);
}