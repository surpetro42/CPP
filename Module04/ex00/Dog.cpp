// #include "Dog.hpp"
// #include "Animal.hpp"



#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog Copy assignment called" << std::endl;	
	if(this != &copy)
	{
		this->type = copy.type;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;	
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}