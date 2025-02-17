#pragma once

#include "Fixed.hpp"
#include <iostream>
#include <cctype>
#include <fstream>
#include <regex>
#include <cmath>


class Point
{
private:
	Fixed const x;
	Fixed const y;
public:
	Point ();
	Point (float, float);
	Point (const Point &copy);
	Point &operator = (const Point &);
	float X() const;
	float Y() const;
	~Point();
};
