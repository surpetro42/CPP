#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{

private:

	std::string name;

public:
    DiamondTrap ();
    DiamondTrap (std::string);
    DiamondTrap &operator=(const ClapTrap &);
    ~DiamondTrap();

    void whoAmI();
};
