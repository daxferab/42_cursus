#include <iostream>
#include <string>
#include "include/Fixed.hpp"
#include "include/Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);
float	side(Point a, Point b, Point p);

int main( void )
{
	const Point	a(0, 0);
	const Point	b(4, 0);
	const Point	c(2, 3);
	// Points to try
	Point	points[] = {
		Point(2, 1),
		Point(2, 1),
		Point(1, 1),
		Point(0, 1),
		Point(4, 1),
		Point(2, -1),
		Point(0, 0),
		Point(1, 1.5)
	};
	for (int i = 0 ; i < 8; i++)
	{
		std::cout << "The point " << points[i];
		if (!bsp(a, b, c, points[i]))
			std::cout << " isn`t ";
		else 
			std::cout << " is ";
		std::cout << "inside the triangle formed by ";
		std::cout << a << ", " << b << " and " << c << "." << std::endl;
		std::cout << a << "--------------------------------------" << std::endl;
	}
	return 0;
}



bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	ab = side(a, b, point);
	float	bc = side(b, c, point);
	float	ca = side(c, a, point);

	return((ab < 0 && bc < 0 && ca < 0) || (ab > 0 && bc > 0 && ca > 0));
}

float	side(Point a, Point b, Point p)
{
	return((b - a) * (p - a));
}
