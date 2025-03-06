#include "Zombie.hpp"

Zombie::Zombie(std::string str)
{
	this->name = str;
	std::cout << "Constructor called" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Destructor called" << std::endl;
}

void   Zombie::SetName(const std::string& value)
{
	name = value;
}
void	Zombie::announce(void) const
{
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::GetName(void)
{
	return name;
}