#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *_materias[4];
public:
    MateriaSource();
    MateriaSource(const MateriaSource &copy);
    MateriaSource& operator=(const MateriaSource &copy);
    virtual ~MateriaSource();
    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};