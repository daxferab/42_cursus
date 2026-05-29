#include "include/PmergeMe.hpp"

#include <climits>
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <vector>
#include <iostream>

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
	mergeInsert(vector, vector.size());
	return (vector);
}

void	PMergeMe::mergeInsert(std::vector<int> &vect, int size)
{
	std::vector<int> main;
	std::vector<int> pend;
	int i = 0;

	while (i < size - 1)
	{
		if (vect[i] < vect[i + 1])
		{
			pend.push_back(vect[i]);
			main.push_back(vect[i + 1]);
		} else {
			pend.push_back(vect[i + 1]);
			main.push_back(vect[i]);
		}
		i += 2;
	}
	if (size % 2 != 0)
		main.push_back(vect[i]);
	vect = main;
	if (vect.size() > 1)
		mergeInsert(vect, vect.size());
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
	//mergeInsert(list, list.size());
	return (list);
}

// void	PMergeMe::mergeInsert(std::list<int> &list, int size)
// {
	
// }

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
