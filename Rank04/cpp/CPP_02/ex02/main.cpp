#include <iostream>
#include "include/Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed	c(2);
	Fixed	d(0);

	std::cout << "'a' float value is " << c << std::endl;
	std::cout << "'b' float value is " << d << std::endl;

	std::cout << "----------COMPARISON----------" << std::endl;
	if (c > d)
		std::cout << c << " > " << d << " is true" << std::endl;
	else
		std::cout  << c << " > " << d << " is false" << std::endl;

	if (c < d)
		std::cout  << c << " < " << d << " is true" << std::endl;
	else
		std::cout  << c << " < " << d << " is false" << std::endl;

	if (c == d)
		std::cout  << c << " == " << d << " is true" << std::endl;
	else
		std::cout  << c << " == " << d << " is false" << std::endl;

	if (c >= d)
		std::cout  << c << " >= " << d << " is true" << std::endl;
	else
		std::cout  << c << " >= " << d << " is false" << std::endl;

	if (c <= d)
		std::cout  << c << " <= " << d << " is true" << std::endl;
	else
		std::cout  << c << " <= " << d << " is false" << std::endl;

	if (c != d)
		std::cout  << c << " != " << d << " is true" << std::endl;
	else
		std::cout  << c << " != " << d << " is false" << std::endl;


	std::cout << "----------ARITHMETIC----------" << std::endl;
	std::cout << c << " + " << d << " = " << (c + d) << std::endl;
	std::cout << c << " - " << d << " = " << (c - d) << std::endl;
	std::cout << c << " * " << d << " = " << (c * d) << std::endl;
	std::cout << c << " / " << d << " = " << (c / d) << std::endl;

	std::cout << "----------Subject----------" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "----------Subject----------" << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << Fixed::max( c, b ) << std::endl;
	std::cout << Fixed::max( c, b ) << std::endl;
	return 0;
}
