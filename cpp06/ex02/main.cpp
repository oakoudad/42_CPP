#include "Base.hpp"
#include <unistd.h>

class TEST:public Base {};

int main()
{
    identify(*generate());
    usleep(915405);
    identify(generate());

    TEST *T = new TEST();
    identify(T);
}