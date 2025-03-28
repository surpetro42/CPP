#pragma once

#include "Brain.hpp"
#include <iostream>
#include <cctype>
#include <fstream>
#include <cmath>

class Animal
{
protected:
	std::string type;
public:
	Animal ();
	Animal (const Animal &copy);
	Animal &operator=(const Animal &copy);
	virtual ~Animal();

	std::string getType() const;
	virtual void makeSound() const;
};
