#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	return new Zombie(name);
}

void randomChump(std::string name)
{
	Zombie zombie(name);
    zombie.announce();
}


int main()
{
    Zombie *zombie;
    std::string name;

    std::cout << "name: ";
    std::cin >> name;
    randomChump(name);
    zombie = newZombie(name);
    zombie->announce();
    delete zombie;
    return (0);
}