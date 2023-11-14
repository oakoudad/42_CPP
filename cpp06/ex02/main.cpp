#include "Base.hpp"
#include <unistd.h>
#include <iostream>

class TEST:public Base {};

int main()
{
    // identify(*generate());
    // usleep(915405);
    // identify(generate());

    // TEST *T = new TEST();
    // identify(T);

    if(dynamic_cast<B *>(new A()))
        std::cout << "Done" << std::endl;

}