#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat Copy assignment called" << std::endl;	
	if(this != &copy)
	{
		this->type = copy.type;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;	
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}