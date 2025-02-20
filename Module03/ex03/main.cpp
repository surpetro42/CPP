#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{

	ClapTrap clap("Clappy");
	clap.attack("Demon");
	clap.takeDamage(5);
	clap.beRepaired(3);
	clap.takeDamage(10);
	clap.attack("Demon");

	ScavTrap scav("Guardian");
	scav.attack("Gago-Loghum");
	scav.guardGate();
	scav.takeDamage(90);
	scav.beRepaired(20);
	scav.attack("Gago-Loghum");


	FragTrap frag("Fraggy");
    frag.attack("Maradonna");
    frag.highFivesGuys();
	scav.takeDamage(90);
	scav.beRepaired(20);
	scav.attack("Maradonna");

	DiamondTrap damage("Diego");
    frag.attack("Aramando");
	damage.whoAmI();
    frag.highFivesGuys();
	scav.takeDamage(90);
	scav.beRepaired(20);
	scav.attack("Aramando");
	return 0;
}