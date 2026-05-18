#include "include/PmergeMe.hpp"
#include <algorithm>

int main(int ac, char **av)
{
	if (ac < 2)
		return error(ERR_ARG);
	if (!vectorContainer(av))
		return 1;
	// if (!secondContainer(av))
	// 	return 1;
	return 0;
}
