#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap " << name << " generated!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
};

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	if (this != &copy)
	{
		name = copy.name;
		hit_points = copy.hit_points;
		energy_points = copy.energy_points;
		attack_damage = copy.attack_damage;
	}
	return *this;
};

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
};

void ClapTrap::attack(const std::string& target)
{
	if(energy_points == 0 || hit_points == 0)
	{
		std::cout << "ClapTrap " << name << " Cannot attack: no energy or HP!" << std::endl;
		return;
	}
	energy_points--;
	std::cout << "ClapTrap " << name << " attacking " << target << ", applying " << attack_damage << " damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points == 0)
	{
		std::cout << "ClapTrap " << name << " Cannot attack: no energy or HP!" << std::endl;
		return ;
	}
	hit_points = (amount >= hit_points) ? 0 : hit_points - amount;
    std::cout << "ClapTrap " << name << " received " << amount << " damage! HP: " << hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points == 0 || hit_points == 0)
	{
		std::cout << "ClapTrap " << name << " Cannot attack: no energy or HP!" << std::endl;
		return ;
	}
	energy_points--;
	hit_points += amount;
	std::cout << "ClapTrap " << name << " received " << amount << " HP: " << hit_points << std::endl;
}