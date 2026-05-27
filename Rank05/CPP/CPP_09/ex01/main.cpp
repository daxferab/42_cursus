#include "include/RPN.hpp"

#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "usage <./RPN input>" << std::endl;
		return (1);
	}

	RPN	solver;
	try
	{
		std::cout << solver.solveOperation(av[1]) << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << std::endl;
	}
	return 0;
}
