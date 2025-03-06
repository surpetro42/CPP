#ifndef HUMANB_HPP 
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <limits>
#include <string>

class HumanB
{
private:
	std::string name;
	std::string type;
	Weapon		weapon;
public:
	HumanB	(std::string value);
	void	setWeapon(Weapon club);
	void	attack();
};

#endif