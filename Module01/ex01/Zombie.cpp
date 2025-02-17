#include "Zombie.hpp"

void Zombie::SetName(std::string value)
{
	name = value;
}

std::string	Zombie::GetName()
{
	return (name);
}

Zombie::Zombie () : name("Unknown")
{

}

Zombie::Zombie (std::string name) : name(name)
{

}
