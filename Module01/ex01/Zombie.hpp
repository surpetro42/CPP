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
    Zombie(const std::string name);
    Zombie();
    ~Zombie();
    void SetName(const std::string& value);
    std::string GetName() const;
    void    announce(std::size_t, Zombie*);
};

Zombie* zombieHorde( int N, std::string name);
#endif