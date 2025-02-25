#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	std::cout << "WrongAnimal constructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Some generic WrongAnimal sound" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal Copy assignment called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return WrongAnimal::type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}