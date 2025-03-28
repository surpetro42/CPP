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

	static Fixed& max(Fixed &, Fixed &);
	static Fixed& min(Fixed &, Fixed &);
	static const Fixed& max(const Fixed &, const Fixed &);
	static const Fixed& min(const Fixed &, const Fixed &);
	
	Fixed ();
	Fixed (float nbr);
	Fixed (int nbr);
	Fixed (const Fixed &copy);

	Fixed &operator = (const Fixed &);
	Fixed &operator ++ ();
	Fixed &operator -- ();

	const Fixed operator ++ (int);
	const Fixed operator -- (int);

	const Fixed	operator+(const Fixed&) const;
	const Fixed	operator-(const Fixed&) const;
	const Fixed operator * (const Fixed&) const;
	const Fixed operator / (const Fixed&) const;

	bool operator > (const Fixed&);
	bool operator < (const Fixed&);
	bool operator >= (const Fixed&);
	bool operator <= (const Fixed&);
	bool operator == (const Fixed&);
	bool operator != (const Fixed&);

	~Fixed();

};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

