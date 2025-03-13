#include "Zombie.hpp"
#include <cstddef>

int main()
{
	std::size_t N = 10;
	Zombie *zombie;
	zombie = zombieHorde(N, "Gago ?");
	zombie->announce(N, zombie);
	delete []zombie;
	return 0;
}
