#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_isBrain;
public:
	Dog ();
	Dog (const Dog &copy);
	Dog &operator=(const Dog &copy);
	virtual ~Dog();

	void makeSound() const;
	void getIdea() const;
	void setIdea(int index, const std::string &idea);
};
