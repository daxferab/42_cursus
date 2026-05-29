#include "include/PmergeMe.hpp"

#include <climits>
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <vector>

// ----------------------------------------------------------------- VECTOR SORT

std::vector<int> PMergeMe::sortVector(int size, char **seq)
{
	std::vector<int>	vector;

	try {
		checkSequence(seq, size);
	} catch (std::exception &e) {
		throw ;
	}
	for (int i = 1; i < size; i++)
		vector.push_back(atol(seq[i]));
	mergeInsert(vector);
	return (vector);
}

void	PMergeMe::mergeInsert(std::vector<int> &vect)
{
	
}

// ------------------------------------------------------------------- LIST SORT

std::list<int> PMergeMe::sortList(int size, char **seq)
{
	std::list<int>	list;

	try {
		checkSequence(seq, size);
	} catch (std::exception &e) {
		throw ;
	}
	for (int i = 1; i < size; i++)
		list.push_back(atol(seq[i]));
	mergeInsert(list);
	return (list);
}

void	PMergeMe::mergeInsert(std::list<int> &list)
{
	
}

// ---------------------------------------------------------------------- Helper

void PMergeMe::checkSequence(char** seq, int size)
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
	}
}
