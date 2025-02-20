#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Dog::Dog()
{
	Animal::type = "Dog";
	_isBrain = new Brain;
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy)
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

void Dog::getIdea() const
{
	for(int i = 0; i < 100; ++i)
	{
		std::cout << "Dog idea " << i << ": " << this->_isBrain->GetIdea(i) << std::endl;
	}
}

void Dog::setIdea(int index, const std::string &idea)
{
	this->_isBrain->SetIdea(index, idea);
}