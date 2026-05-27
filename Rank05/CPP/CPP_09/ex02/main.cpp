#include "include/PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
		return error(ERR_ARG);

	if (!printInts(ac, av))
		return error(ERR_SEQUENCE);
	// vectorMergeInsert(av);
	// listMergeInsert(av);
	return 0;
}
