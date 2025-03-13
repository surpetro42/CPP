#include "Zombie.hpp"
#include <cstddef>
#include <iterator>

void Zombie::SetName(const std::string& value)
{
	name = value;
}

void	Zombie::announce(std::size_t N, Zombie *zombie)
{
	for(std::size_t i = 0; i < N; ++i)
		std::cout << "name: " << zombie->GetName() << std::endl;
}

std::string	Zombie::GetName() const
{
	return (name);
}

Zombie::~Zombie()
{
	std::cout << "Zombies are being destroyed " << std::endl;
};

Zombie::Zombie () : name("Unknown") {}

Zombie::Zombie (const std::string name) : name(name) {}
