#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat()
{
	type = "Cat";
	_isBrain = new Brain;
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->type = copy.type;
	_isBrain = new Brain(*copy._isBrain);
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat Copy assignment called" << std::endl;	
	if(this != &copy)
	{
		this->type = copy.type;
		if (_isBrain)
            delete _isBrain;
		_isBrain = new Brain(*copy._isBrain);
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
	delete _isBrain;
}

std::string Cat::getIdea(size_t index) const
{
	return this->_isBrain->GetIdea(index);
}

void Cat::setIdea(int index, const std::string &idea)
{
	this->_isBrain->SetIdea(index, idea);
}