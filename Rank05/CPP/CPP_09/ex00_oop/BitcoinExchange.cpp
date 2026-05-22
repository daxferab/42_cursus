#include "include/BitcoinExchange.hpp"

#include <iostream>

static const	std::string g_error[] = 
{
	"usage <./btc input>.",
	"couldn't open file.",
	"wrong input => ",
	"input header is not date | value"
};

bool	error(int i)
{
	std::cerr << RED << "Error: " << g_error[i] << std::endl;
	return false;
}

void	printCoversion(float value, float amount, std::string date)
{
	float result = value * amount;
	std::cout << date << " => " << amount << " = " << result << std::endl;
}
