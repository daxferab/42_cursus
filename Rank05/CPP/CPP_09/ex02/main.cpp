#include "include/PmergeMe.hpp"
#include <bits/types/struct_timeval.h>
#include <exception>
#include <vector>
#include <iostream>
#include <ctime>

int main(int ac, char **av)
{
	if (ac < 2)
		return error(ERR_ARG);

	std::vector<int>	sortedVect;
	std::list<int>		sortedList;
	double timeVect;
	double timeList;
	try {
		timeVect = vectorMergeInsert(ac, av, sortedVect);
		timeList = listMergeInsert(ac, av, sortedList);
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << std::endl;
		return 1;
	}
	(void)timeVect;
	printFormat(ac, av, sortedVect, timeVect, timeList);
	return 0;
}
