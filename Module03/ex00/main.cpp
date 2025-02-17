#include "ClapTrap.hpp"

int main()
{
	ClapTrap knight("Clappy");

	knight.attack("Demon");
	knight.takeDamage(5);
	knight.beRepaired(3);
	knight.takeDamage(10);
	knight.attack("Demon");
	knight.takeDamage(5);
	
	return 0;
}