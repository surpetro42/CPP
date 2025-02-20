#pragma once

#include <iostream>
#include <cctype>
#include <fstream>
#include <regex>
#include <cmath>

class ClapTrap
{
protected:

	std::string name;
	unsigned int hit_points;
	unsigned int energy_points;
	unsigned int attack_damage;

public:

	ClapTrap (std::string);
    ClapTrap (const ClapTrap &);
    ClapTrap &operator=(const ClapTrap &);
    ~ClapTrap();
	
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
