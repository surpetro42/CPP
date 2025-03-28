#include "Cure.hpp"

Cure::Cure () : AMateria("cure") {}

AMateria* Cure::clone() const
{
    return (new Cure());
}

void Cure::use(ICharacter& target)
{
    std::cout << "Cure: * heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy) {}

Cure& Cure::operator=(const Cure &copy)
{
    if(this != &copy)
    {
        AMateria::operator=(copy);
    }
    return *this;
}

Cure::~Cure(void) {}