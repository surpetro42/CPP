#include "Zombie.hpp"

int main()
{
    Zombie *zombie;
    std::string name;

    std::cout << "name:";
    std::cin >> name;
    std::cout << std::endl;
    randomChump(name);
    zombie = newZombie(name);
    delete zombie;
    return (0);
}