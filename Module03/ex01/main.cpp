#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{

	ClapTrap clap("Clappy");
	clap.attack("Enemy");
	clap.takeDamage(5);
	clap.beRepaired(3);
	clap.takeDamage(10);
	clap.attack("Enemy");

	ScavTrap scav("Guardian");
	scav.attack("EvilBot");
	scav.guardGate();
	scav.takeDamage(90);
	scav.beRepaired(20);
	scav.attack("EvilBot");

	return 0;
}