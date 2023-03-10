#include "Harl.hpp"

int main()
{
    Harl H;

    H.complain("DEBUG");
    H.complain("INFO");
    H.complain("WARNING");
    H.complain("ERROR");
    system("leaks Harl");
}