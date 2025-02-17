#ifndef HUMANA_HPP 
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <limits>
#include <string>

class HumanA
{
private:
	std::string name;
    std::string type;
	Weapon		weapon;
public:
	void	setType(std::string value);
	HumanA();
    HumanA (std::string value, Weapon weapon);
	void attack();
};

#endif