#pragma once

#include <iostream>
#include <cctype>
#include <fstream>
#include <regex>
#include <string>

class Fixed
{
private:
	int					fixed_point;
	static const int 	fractionalBits = 8;
public:
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	Fixed ();
	Fixed (const Fixed &copy);
	Fixed &operator = (const Fixed &copy);
	~Fixed();
};
