#pragma once

#include "Animal.hpp"
#include <string>

class Cat : public Animal
{
private:
	std::string type;
public:
	Cat();
	Cat(const Cat &copy);
    Cat &operator=(const Cat &copy);
	virtual ~Cat();

	void makeSound() const;
};
