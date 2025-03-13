#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() 
{
	std::cout << "Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap " << name << " created!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (energy_points <= 0 || hit_points <= 0)
	{
		std::cout << "ScavTrap " << name << " Cannot attack: no energy or HP!" << std::endl;
		return;
	}
	energy_points--;
	std::cout << "ScavTrap " << name << " attacking " << target << ", applying " << attack_damage << " damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap Guardian has entered protection mode!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destroyed!" << std::endl;
};