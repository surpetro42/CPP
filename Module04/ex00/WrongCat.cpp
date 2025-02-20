#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat()
{
	WrongAnimal::type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

std::string WrongCat::getType() const
{
	return WrongCat::type;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "WrongCat Copy assignment called" << std::endl;
	if(this != &copy)
	{
		this->type = copy.type;
	}
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;	
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}