#include "include/RPN.hpp"
#include <list>

int main(int ac, char **av)
{
	if (ac != 2)
		return (error(ERR_ARG, ""));

	std::list<char>	operation;
	if (!parseOperation(&operation, av[1]))
		return (1);
}
