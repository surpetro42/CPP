#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

Weapon::Weapon()
{

}

Weapon::Weapon(std::string value)
{
	type = value;
}

void Weapon::setType(std::string value)
{
	type = value;
	std::cout << type << std::endl;
}

std::string	Weapon::GetName()
{
	return (type);
}
