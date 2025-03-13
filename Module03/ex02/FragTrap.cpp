#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() 
{
	std::cout << "Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 20;
	std::cout << "FragTrap " << name << " created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap copied!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
	{
        ClapTrap::operator=(other);
        std::cout << "FragTrap assigned!" << std::endl;
    }
    return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap" << name << "He says: Give me five, guys!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destroyed!" << std::endl;
};