#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_brain;
public:
	Dog ();
	Dog (const Dog &copy);
	Dog &operator=(const Dog &copy);
	virtual ~Dog();

	void makeSound() const;
	const std::string getIdeas(size_t i) const;
	void setIdea(size_t i, std::string idea) const;
};
