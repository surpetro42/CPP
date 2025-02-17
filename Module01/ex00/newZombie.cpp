#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *zombie = new Zombie();
	zombie->SetName(name);
	std::cout << "foo:" << zombie->GetName() << std::endl;
	return zombie;
}