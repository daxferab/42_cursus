#include "include/RPN.hpp"

#include <list>
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
		return (error(ERR_ARG, ""));

	std::list<std::string>	operation;
	if (!parseInput(operation, av[1]))
		return 1;

	std::cout << solveOperation(operation) << std::endl;
	return 0;
}
