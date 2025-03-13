#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

Weapon::Weapon()
{

}

Weapon::Weapon(const std::string& value) : type(value) {}

void Weapon::setType(const std::string& value)
{
	type = value;
	std::cout << type << std::endl;
}

const std::string&	Weapon::GetName() const
{
	return (type);
}

Weapon::~Weapon(){};
