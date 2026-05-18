#include "include/PmergeMe.hpp"

#include <ctime>
#include <iostream>

bool error(int i)
{
	std::cerr << RED << "Error: " << g_error[i] << std::endl;
	return false;
}

// ------------------------------ First container

bool	vectorContainer(char **list)
{
	time_t	*timer = 0;
	time(timer);
	// int i = 0;

	// while (list[i])
	// {
	// 	if (!isNum(list[i]))
	// 		return(error(ERR_SEQUENCE));
	// 	if (isRepeated(list[i]))
	// }
	(void)list;
	std::cout << timer << std::endl;
	return false;
}

// ------------------------------ Second container
