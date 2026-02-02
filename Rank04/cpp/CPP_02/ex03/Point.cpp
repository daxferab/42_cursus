#include "include/Point.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

Point::Point() : _x(0), _y(0){}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY()) {}

Point& Point::operator=(const Point &other)
{
	if (this != &other) {
		_x = other.getX();
		_y = other.getY();
	}

	return (*this);
}

Point::~Point(){}


Point Point::operator-(const Point &other) const
{
	float	xCoord = getX().toFloat() - other.getX().toFloat();
	float	yCoord = getY().toFloat() - other.getY().toFloat();
	return(Point(xCoord, yCoord));
}

float Point::operator*(const Point &other) const //Cross product
{
	float	xy = getX().toFloat() * other.getY().toFloat();
	float	yx = getY().toFloat() * other.getX().toFloat();
	return(xy - yx);
}

/***************************** MEMBER FUNCTIONS *******************************/

Fixed	Point::getX() const
{
	return(_x);
}

Fixed	Point::getY() const
{
	return(_y);
}

std::ostream& operator<<(std::ostream& os, const Point& f)
{
    os << "(" << f.getX() << ", " << f.getY() << ")";
    return os;
}

