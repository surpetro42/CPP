#include "Zombie.hpp"
#include <cstddef>

void Zombie::SetName(const std::string& value)
{
	name = value;
}

void	Zombie::announce(int N, Zombie *zombie)
{
	for(std::size_t i = 0; i < N; ++i)
		std::cout << "name: " << zombie->GetName() << std::endl;
}

std::string	Zombie::GetName() const
{
	return (name);
}

Zombie::~Zombie() {};

Zombie::Zombie () : name("Unknown") {}

Zombie::Zombie (const std::string name) : name(name) {}
