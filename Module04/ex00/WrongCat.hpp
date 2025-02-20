#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
	std::string type;
public:
	WrongCat();
	WrongCat(const WrongCat &copy);
    WrongCat &operator=(const WrongCat &copy);
	virtual ~WrongCat();
	void makeSound() const;
	std::string getType() const;
};
