#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure(const Cure &copy);
    Cure &operator=(const Cure &copy);
    virtual ~Cure();
    virtual AMateria *clone() const;
    virtual void use(ICharacter &target);
};
