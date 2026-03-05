#include "include/whatever.hpp"
#include <iostream>

int main( void )
{
	std::cout << std::endl << "----------------INT---------------" << std::endl << std::endl;
	int a = 2;
	int b = 3;
	std::cout << "Created a and b:" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	std::cout << std::endl;

	::swap( a, b );
	std::cout << "Swapped a and b:" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	std::cout << std::endl;

	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << std::endl << "---------------STRING--------------" << std::endl << std::endl;
	std::string c = "string1";
	std::string d = "string2";
	std::cout << "Created c and d:" << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	std::cout << std::endl;

	::swap(c, d);
	std::cout << "Swapped c and d:" << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	std::cout << std::endl;

	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << std::endl << "---------------DOUBLE-------------" << std::endl << std::endl;
	double e = 2.5676575;
	double f = 9.2998443;
	std::cout << "Created e and f:" << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "f = " << f << std::endl;

	std::cout << std::endl;

	::swap( e, f );
	std::cout << "Swapped e and f:" << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "f = " << f << std::endl;

	std::cout << std::endl;

	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
	return 0;
}
