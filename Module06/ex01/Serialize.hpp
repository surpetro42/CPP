#pragma once

#include <iostream>
#include <inttypes.h>

struct  Data
{
    std::string name;
};

class Serialize
{
    Serialize();
    Serialize(const Serialize &);
    Serialize &operator=(const Serialize &);
    ~Serialize();
public:

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};