#pragma once

#include <iostream>
#include <cctype>
#include <fstream>
#include <cmath>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);
	WrongAnimal &operator=(const WrongAnimal &copy);
	virtual ~WrongAnimal();
	void makeSound() const;
	std::string getType() const;
};
