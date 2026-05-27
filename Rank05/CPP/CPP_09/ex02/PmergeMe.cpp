#include "include/PmergeMe.hpp"

#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <climits>

bool error(int i)
{
	std::cerr << RED << "Error: " << g_error[i] << std::endl;
	return false;
}

bool	printInts(int size, char **args)
{
	int j;

	for (int i = 1; i < size; i++)
	{
		j = 0;
		if (std::atol(args[i]) > INT_MAX) return false;
		while (args[i][j])
			if (!isdigit(args[i][j++])) return(false);
	}
	std::cout << "Before: ";
	for (int i = 1; i < size; i++)
		std::cout << args[i] << " ";		
	std::cout << std::endl;
	return true;
}
