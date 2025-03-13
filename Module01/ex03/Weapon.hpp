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
	Weapon (const std::string& value);
    Weapon();
    ~Weapon();
    const std::string& GetName() const;
    void setType(const std::string& value);
};

#endif