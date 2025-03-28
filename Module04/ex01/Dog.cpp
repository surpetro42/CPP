#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <cstddef>

Dog::Dog()
{
	type = "Dog";
	_isBrain = new Brain;
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->type = copy.type;
	_isBrain = new Brain(*copy._isBrain);
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog Copy assignment called" << std::endl;	
	if(this != &copy)
	{
		this->type = copy.type;
		if (_isBrain)
			delete(_isBrain);
		_isBrain = new Brain(*copy._isBrain);
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
	delete _isBrain;
}

std::string Dog::getIdea(size_t index) const
{
	return this->_isBrain->GetIdea(index);
}

void Dog::setIdea(int index, const std::string &idea)
{
	this->_isBrain->SetIdea(index, idea);
}