#include "include/PmergeMe.hpp"

#include <climits>
#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <vector>

bool error(int i)
{
	std::cerr << RED << "Error: " << g_error[i] << std::endl;
	return false;
}

bool	printFormat(int size, char **args, std::vector<int> vect, double vtime, double ltime)
{
	std::cout << "Before: ";
	for (int i = 1; i < size; i++)
		std::cout << args[i] << " ";		
	std::cout << std::endl;

	std::cout << "After: ";
	for (std::vector<int>::iterator it = vect.begin(); it < vect.end();it++)
		std::cout << *it << " ";		
	std::cout << std::endl;

	std::cout << "Time to process a range of " << size - 1 << " elements with std::vector: " << vtime << " us" << std::endl;

	std::cout << "Time to process a range of " << size - 1 << " elements with std::list: " << ltime << " us" << std::endl;
	return true;
}

double	vectorMergeInsert(int size, char **seq, std::vector<int>& vect)
{
	for (int i = 1; i < size; i++)
	{
		int	j = 0;
		if (atol(seq[i]) > INT_MAX)
			throw std::logic_error("argument must be a positive integer sequence");
		while (seq[i][j])
		{
			if (!isdigit(seq[i][j++]))
				throw std::logic_error("argument must be a positive integer sequence");
		}
		vect.push_back(atol(seq[i]));
	}
	
	return 0;
}

double	listMergeInsert(int size, char **seq, std::list<int>& list)
{
	for (int i = 1; i < size; i++)
	{
		int	j = 0;
		if (atol(seq[i]) > INT_MAX)
			throw std::logic_error("argument must be a positive integer sequence");
		while (seq[i][j])
		{
			if (!isdigit(seq[i][j++]))
				throw std::logic_error("argument must be a positive integer sequence");
		}
		list.push_back(atol(seq[i]));
	}
	return 0;
}
