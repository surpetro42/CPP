#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.GetName() << std::endl;
}

HumanA::HumanA(const std::string &value, const Weapon &club) : name(value), weapon(club) 
{
	std::cout  << "HumanA " << name << " was created with their " << weapon.GetName() << std::endl;
}

void	HumanA::setType(const std::string& value)
{
	type = value;
}

HumanA::~HumanA(){};