#include "include/print.hpp"
#include <iostream>

bool	printFormat(int size, char **args, std::vector<int> vect, double vtime, double ltime)
{
	std::cout << "Before: ";
	for (int i = 1; i < size; i++)
		std::cout << args[i] << " ";		
	std::cout << std::endl;

	std::cout << "After: ";
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end();it++)
		std::cout << *it << " ";		
	std::cout << std::endl;

	std::cout << "Time to process a range of " << size - 1 << " elements with std::vector: " << vtime << " μs" << std::endl;
	
	std::cout << "Time to process a range of " << size - 1 << " elements with std::list: " << ltime << " μs" << std::endl;
	return true;
}
