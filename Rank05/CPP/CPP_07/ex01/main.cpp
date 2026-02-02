#include "include/iter.hpp"
#include <iostream>

int main ()
{
	int				arrayInts[] = {1, 2, 3, 4};
	char			arrayChar[] = {'a', 'b', 'c', 'd'};
	double			arrayDouble[] = {1.5, 0.6, 3.5, 7.4};
	size_t const	length = 4;

	std::cout << "Original Ints Array: { ";
	iter(arrayInts, length, print<int>);
	std::cout << "}" << std::endl;

	iter(arrayInts, length, increment<int>);

	std::cout << "Incremented Ints Array: { ";
	iter(arrayInts, length, print<int>);
	std::cout << "}" << std::endl;

	std::cout << "---------------------------------------" << std::endl;

	std::cout << "Original Char Array: { ";
	iter(arrayChar, length, print<char>);
	std::cout << "}" << std::endl;

	iter(arrayChar, length, increment<char>);

	std::cout << "Incremented Char Array: { ";
	iter(arrayChar, length, print<char>);
	std::cout << "}" << std::endl;

	std::cout << "---------------------------------------" << std::endl;

	std::cout << "Original Double Array: { ";
	iter(arrayDouble, length, print<double>);
	std::cout << "}" << std::endl;

	iter(arrayDouble, length, increment<double>);

	std::cout << "Incremented Double Array: { ";
	iter(arrayDouble, length, print<double>);
	std::cout << "}" << std::endl;

	std::cout << "---------------------------------------" << std::endl;
	std::cout << "Trying iter with const char: " << std::endl;
	const char arrayConst[] = {'h', 'e', 'l', 'l'};
	iter(arrayConst, length, print<char>);

	return 0;
}
