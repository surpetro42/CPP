#include "Point.hpp"
#include "Fixed.hpp"

Point &Point::operator = (const Point &copy)
{
	if (this != &copy)
	{
		(Fixed)this->x = copy.x;
		(Fixed)this->y = copy.y;
	}
	return *this;
}

float	Point::X ( void ) const
{
	return (this->x.toFloat());
}

float	Point::Y ( void ) const
{
	return (this->y.toFloat());
}

Point::Point(const Point &copy) : x(copy.X()), y(copy.Y()) {}

Point::Point(float a, float b) : x(a), y(b) {}

Point::Point() : x (0), y (0) {}

Point::~Point() {};