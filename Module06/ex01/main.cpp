#include "Serialize.hpp"

int main()
{
    Data obj;

    std::cout << &obj << std::endl;
    Data *ptr = Serialize::deserialize(Serialize::serialize(&obj));
    std::cout << ptr << std::endl;
    return 0;
}