#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Some generic animal sound" << std::endl;
}

Animal::Animal(const Animal &copy) : type(copy.type)
{
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
	std::cout << "Animal Copy assignment called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

std::string Animal::getType() const
{
	return this->type;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}