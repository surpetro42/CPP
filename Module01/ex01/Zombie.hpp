#ifndef ZOMBIE_HPP 
#define ZOMBIE_HPP

#include <iostream>
#include <limits>
#include <string>

class Zombie
{
private:
    std::string name;
public:
    Zombie(std::string name);
    Zombie();
    void SetName(std::string value);
    std::string GetName();
    void    announce(void);
};

Zombie* zombieHorde( int N, std::string name);
#endif