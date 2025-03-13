#include "Zombie.hpp"
#include <algorithm>

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombie;
	int i = 0;
	zombie = new Zombie[N]();
	while (i < N)
	{
		std::cout << "creates zombies" << std::endl;
		zombie[i].SetName(name);
		i++;
	}
	return zombie;
}