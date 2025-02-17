#pragma once

#include <iostream>
#include <cctype>
#include <fstream>
#include <regex>
#include <cmath>


class Fixed
{
private:
	int					fixed_point;
	static const int 	fractionalBits = 8;
public:
	int toInt() const;
    float toFloat() const; 
	Fixed ();
	Fixed (float nbr);
	Fixed (int nbr);
	Fixed (const Fixed &copy);
	Fixed &operator = (const Fixed &copy);
	~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

