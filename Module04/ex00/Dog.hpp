#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
private:
	std::string type;
public:
	Dog ();
	Dog (const Dog &copy);
	Dog &operator=(const Dog &copy);
	virtual ~Dog();

	void makeSound() const;

};
