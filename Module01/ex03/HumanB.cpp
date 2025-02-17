// #include "HumanA.hpp"
#include "HumanB.hpp"
#include "HumanA.hpp"
#include "Weapon.hpp"

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon.GetName() << std::endl;
}

HumanB::HumanB(std::string value)
{
	name = value;
	std::cout << "HumanB " << name << " was created with their " << weapon.GetName() << std::endl;
}

void	HumanB::setWeapon(Weapon club)
{
	weapon = club;
}