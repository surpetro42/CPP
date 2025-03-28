#pragma once

#include <iostream>
#include <cctype>
#include <fstream>
#include <cmath>

class ClapTrap
{
protected:

	std::string name;
	unsigned int hit_points;
	unsigned int energy_points;
	unsigned int attack_damage;

public:
	ClapTrap ();
	ClapTrap (std::string);
    ClapTrap (const ClapTrap &);
    ClapTrap &operator=(const ClapTrap &);
    virtual ~ClapTrap();
	
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
