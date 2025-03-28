#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _materias[i] = NULL;
}

MateriaSource::MateriaSource (const MateriaSource &copy)
{
    for (int i = 0; i < 4; i++)
        _materias[i] = copy._materias[i] ? copy._materias[i]->clone() : 0;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 4; i++)
        {
            if(_materias[i])
                delete _materias[i];
            _materias[i] = copy._materias[i] ? copy._materias[i]->clone() : NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i])
            delete _materias[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    for(int i = 0; i < 4; ++i)
    {
        if(!_materias[i])
        {
            _materias[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for(int i = 0; i < 4; ++i)
    {
        if(_materias[i] && _materias[i]->getType() == type)
            return _materias[i]->clone();
    }
    return NULL;
}