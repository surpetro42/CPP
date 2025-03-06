#ifndef ZOMBIE_HPP 
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
    std::string name;
public:
    Zombie(std::string);
    ~Zombie();

    const   std::string& GetName() const;
    void    SetName(const std::string& value);
    std::string GetName(void);
    void    announce(void) const;
};

#endif 