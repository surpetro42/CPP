#ifndef ZOMBIE_HPP 
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
    std::string name;
public:
    void SetName(std::string value);
    std::string GetName();
    void    announce(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );


#endif 