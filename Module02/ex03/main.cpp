#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	const Point a;
	const Point b(10, 0);
	const Point c(0, 10);
	const Point point(1, 1);

	std::cout << "The point( x= " << point.X() << "\t\ty= " << point.Y() << "\t) is inside the triangle\n" <<
	"\ta( x= " << a.X() << "\t\ty= " << a.Y() << "\t)\n" <<
	"\tb( x= " << b.X() << "\ty= " << b.Y() << "\t)\n" <<
	"\tc( x= " << c.X() << "\t\ty= " << c.Y() << "\t)\n" << std::endl;
	if (bsp(a, b, c, point) == true)
		std::cout << "\033[32mTRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31mFALSE\033[0m" << std::endl;
	return 0;
}
