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
	const Weapon		*weapon;
public:
	HumanB	(const std::string& value);
	~HumanB();
	void	setWeapon(const Weapon *club);
	void	attack() const;
};

#endif