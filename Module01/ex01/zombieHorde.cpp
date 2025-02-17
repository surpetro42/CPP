#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombie;
	int i = 0;
	zombie = new Zombie[N]();
	while (i < N)
	{
		zombie[i].SetName(name);
		i++;
	}
	return zombie;
}