#ifndef WEAOPON_HPP 
#define WEAOPON_HPP

#include <iostream>
#include <limits>
#include <string>

class Weapon
{
private:
    std::string type;
public:
    Weapon();
	Weapon (std::string value);
    std::string GetName();
    void setType(std::string value);
};

#endif