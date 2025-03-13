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
	const Weapon	&weapon;
public:
	HumanA();
    HumanA (const std::string &value, const Weapon &) ;
	void	setType(const std::string& value);
	~HumanA();
	void	attack();
};

#endif