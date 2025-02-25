	#pragma once

	#include "Animal.hpp"
#include <cstddef>
	#include "Brain.hpp"
	#include <string>

	class Cat : public Animal
	{
	private:
		Brain *_isBrain;
	public:
		Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &copy);
		virtual ~Cat();

		void makeSound() const;
		std::string getIdea(size_t) const;
		void setIdea(int index, const std::string &idea);
	};
