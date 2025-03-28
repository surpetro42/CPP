#pragma once

#include <iostream>
#include <cctype>
#include <fstream>
#include <cmath>


class Fixed
{
private:
	int					fixed_point;
	static const int 	fractionalBits = 8;
public:
	int toInt() const;
    float toFloat() const; 
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	Fixed ();
	Fixed (const float nbr);
	Fixed (const int nbr);
	Fixed (const Fixed &copy);
	Fixed &operator = (const Fixed &copy);
	~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);
