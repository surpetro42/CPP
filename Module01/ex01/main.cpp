#include "Zombie.hpp"

int main()
{
	int N = 10;
	Zombie *zombie;
	zombie = zombieHorde(N, "Zombie");
	zombie->announce(N, zombie);
	delete []zombie;
	return 0;
}
