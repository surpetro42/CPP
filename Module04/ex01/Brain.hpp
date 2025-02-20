#pragma once

#include <cstddef>
#include <iostream>
#include <cctype>
#include <fstream>
#include <regex>
#include <cmath>
#include <string>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
	~Brain();

	void SetIdea(size_t i, const std::string ideas);
	const std::string GetIdea(size_t i) const;
};
