// #include "HumanA.hpp"
#include "HumanB.hpp"
#include "HumanA.hpp"
#include "Weapon.hpp"

void	HumanB::attack() const
{
	std::cout << name << " attacks with their " << weapon->GetName() << std::endl;
}

HumanB::HumanB(const std::string& value) : name(value)
{
	std::cout << "HumanB " << name << " was created " << std::endl;
}

void	HumanB::setWeapon(const Weapon *club)
{
	weapon = club;
}

HumanB::~HumanB(){};