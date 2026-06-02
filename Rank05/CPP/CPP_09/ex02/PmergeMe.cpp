#include "include/PmergeMe.hpp"
#include "include/Jacobsthal.hpp"

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <exception>
#include <iterator>
#include <list>
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
	vector.reserve(size - 1);
	for (int i = 1; i < size; i++)
		vector.push_back(atol(seq[i]));
	mergeInsert(vector, vector.size());
	return (vector);
}

void	PMergeMe::mergeInsert(std::vector<int> &vect, int size)
{
	std::vector<int>	main;
	std::vector<int>	pend;
	int					i = 0;

	main.reserve((size + 1) / 2);
	main.reserve(size / 2);
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

	if (main.size() > 1)
		mergeInsert(main, main.size());

	insertMain(main, pend);
	vect.swap(main);
}

void PMergeMe::insertMain(std::vector<int>& main, std::vector<int>& pend)
{
	std::vector<int>	order = Jacobsthal::getFullSequence(pend.size());
	int					element;

	for (size_t i = 0; i < order.size(); i++)
	{
		element = pend[order[i] - 1];
		insert(element, main);
	}
}

void PMergeMe::insert(int element, std::vector<int> &main)
{
	std::vector<int>::iterator pos = std::upper_bound(main.begin(), main.end(), element);
	main.insert(pos, element);
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
	mergeInsert(list, list.size());
	return (list);
}

void	PMergeMe::mergeInsert(std::list<int> &list, int size)
{
	std::list<int> main;
	std::list<int> pend;
	std::list<int>::iterator curr = list.begin();
	std::list<int>::iterator next = curr;
	int i = 0;

	std::advance(next, 1);
	while (i < size / 2)
	{
		if (*curr < *next)
		{
			pend.push_back(*curr);
			main.push_back(*next);
		} else {
			pend.push_back(*next);
			main.push_back(*curr);
		}
		std::advance(curr, 2);
		std::advance(next, 2);
		i++;
	}
	if (size % 2 != 0)
		main.push_back(*curr);
	list = main;
	if (list.size() > 1)
		mergeInsert(list, list.size());

	insertMain(list, pend);
}

void PMergeMe::insertMain(std::list<int>& main, std::list<int>& pend)
{
    std::vector<int> order = Jacobsthal::getFullSequence(pend.size());

    for (size_t i = 0; i < order.size(); ++i)
    {
        std::list<int>::iterator it = pend.begin();
        std::advance(it, order[i] - 1);
        insert(*it, main);
    }
}

void PMergeMe::insert(int element, std::list<int> &main)
{
	std::list<int>::iterator pos = std::upper_bound(main.begin(), main.end(), element);
	main.insert(pos, element);
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
