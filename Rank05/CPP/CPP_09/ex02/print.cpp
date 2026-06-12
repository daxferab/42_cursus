#include "include/print.hpp"
#include <iostream>

#define RED "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"


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

	std::cout << "Time to process a range of " << YELLOW << size - 1 << RESET << " elements with " << GREEN << "std::vector: " << RED << vtime << " μs" << RESET << std::endl;
	
	std::cout << "Time to process a range of " << YELLOW << size - 1 << RESET << " elements with " << GREEN << "std::list: "  << RED << ltime << " μs" << std::endl;
	return true;
}
