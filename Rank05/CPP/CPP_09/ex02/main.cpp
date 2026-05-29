#include "include/PmergeMe.hpp"
#include "include/Timer.hpp"
#include "include/print.hpp"
#include <exception>
#include <vector>
#include <iostream>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << RED << "usage <./PmergeMe input>" << std::endl;
		return 1;
	}

	Timer timer;
	std::vector<int> vector;
	std::list<int> list;

	timer.start();
	try {
		vector = PMergeMe::sortVector(ac, av);
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << std::endl;
		return 1;
	}
	double vectorTime = timer.stop();

	timer.start();
	try {
		list = PMergeMe::sortList(ac, av);
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << std::endl;
		return 1;
	}
	double listTime = timer.stop();

	printFormat(ac, av, vector, vectorTime, listTime);
	return 0;
}
