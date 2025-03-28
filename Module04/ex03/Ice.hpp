#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice &copy);
    Ice &operator=(const Ice &copy);
    virtual ~Ice();
    virtual AMateria *clone() const;
    virtual void use(ICharacter &target);
};
