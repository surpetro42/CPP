#include "Point.hpp"
#include "Fixed.hpp"

static float zone (const Point point1, const Point point2, const Point point3)
{
	float	area;

	area =	( (point1.X() * (point2.Y() - point3.Y()))
			+ (point2.X() * (point3.Y() - point1.Y()))
			+ (point3.X() * (point1.Y() - point2.Y()))
			) / 2;

	if (area >= 0)
		return (area);
	else
		return (area * -1);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float b1, b2, b3, b4;
	bool ret_val = false;

	b1 = zone(a, b, c);
	b2 = zone(point, a, b);
	b3 = zone(point, b, c);
	b4 = zone(point, a, c);

	if (b2 == 0 || b3 == 0 || b4 == 0)
		ret_val = false;
	else if (b2 + b3 + b4 == b1)
		ret_val = true;

	return (ret_val);
}
