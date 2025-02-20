#include "Brain.hpp"

Brain::Brain()
{
   std::cout << "Brain constructor was called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor was called" << std::endl;
	for(int i = 0; i < 100; ++i)
		this->ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain& other)
{
	std::cout << "Brain Copy assignment called" << std::endl;
	if (this != &other)
	{
		for(int i = 0; i < 100; ++i)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

const std::string Brain::GetIdea(size_t i) const
{
	if (i < 100)
		return this->ideas[i];
	else
    	return ("100 ideas per brain!");
}

void Brain::SetIdea(size_t i, const std::string ideas)
{
	if (i < 100)
		this->ideas[i] = ideas;
	else
	 	std::cout << "100 ideas per brain!" << std::endl;;
}