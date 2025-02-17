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
	scav.attack("EvilBot");
	scav.guardGate();
	scav.takeDamage(90);
	scav.beRepaired(20);
	scav.attack("EvilBot");


	FragTrap frag("Fraggy");
    frag.attack("Bandit");
    frag.highFivesGuys();
	scav.takeDamage(90);
	scav.beRepaired(20);
	scav.attack("Bandit");
	return 0;
}