#include "Serialization.hpp"

void change(uintptr_t uint_s)
{
    Data *data_s = (Data *)Serializer::deserialize(uint_s);
    data_s->_float = 42.1337;
    data_s->_char  = 'B';
}

int main()
{
    Data data;

    data._float = 1337.42;
    data._char  = 'A';

    std::cout << "Struct add: " << &data << "\t(" << data._float << " - " << data._char << ")" << std::endl;
    uintptr_t uint_s = Serializer::serialize(&data);
    change(uint_s);
    std::cout << "Uint value: 0x" << std::hex << uint_s << "\t";

    Data *data_s = (Data *)Serializer::deserialize(uint_s);
    std::cout << "(" << data_s->_float << " - " << data_s->_char << ")" << std::endl;
}