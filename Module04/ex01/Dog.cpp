#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Dog::Dog()
{
	Animal::type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	delete _brain;
	this->_brain = new Brain;
	this->_brain = copy._brain;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog Copy assignment called" << std::endl;	
	if(this != &copy)
	{
		delete this->_brain;
		this->_brain = new  Brain;
		for(int i = 0; i < 100; ++i)
			this->_brain[i] = copy._brain[i];
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
	delete this->_brain;
}

const std::string Dog::getIdeas(size_t i) const
{
	return this->_brain->GetIdea(i);
}

void Dog::setIdea(size_t i, std::string idea) const
{
	this->_brain->SetIdea(i, idea);
}