#include "Zombie.hpp"

void	announce(int N, Zombie *zombie)
{
	for(int i = 0; i < N; ++i)
		std::cout << zombie->GetName() << std::endl;
}

int main()
{
	int N = 10;
	Zombie *zombie;
	zombie = zombieHorde(N, "qwe>???");
	announce(N, zombie);
	delete []zombie;
	return 0;
}
