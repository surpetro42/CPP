#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}

DiamondTrap::DiamondTrap(std::string D_name)
	: ClapTrap(D_name += "_clap_name"), FragTrap(D_name),  ScavTrap(D_name)
{
	hit_points = FragTrap::hit_points;
	energy_points = ScavTrap::energy_points;
	attack_damage = FragTrap::attack_damage;
}

DiamondTrap::~DiamondTrap() {};