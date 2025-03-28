#include "Character.hpp"

Character::Character() : _name("Default")
{
    std::cout << "Default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(const std::string &name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character (const Character &copy) : _name(copy._name)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = copy._inventory[i] ? copy._inventory[i]->clone() : NULL;
}

Character& Character::operator=(const Character &copy)
{
    if (this != &copy)
    {
        _name = copy._name;
        for (int i = 0; i < 4; i++)
        {
            delete _inventory[i];
            _inventory[i] = copy._inventory[i] ? copy._inventory[i]->clone() : NULL;
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if(_inventory[i])
            delete _inventory[i];
    }
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if(idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx <= 4 && _inventory[idx])
        _inventory[idx]->use(target);
}