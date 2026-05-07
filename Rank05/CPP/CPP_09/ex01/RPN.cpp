#include "include/RPN.hpp"

#include <iostream>

bool	error(int i)
{
	std::cerr << "Error: " << g_error[i];
	return false;
}
