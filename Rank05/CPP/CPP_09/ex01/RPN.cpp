#include "include/RPN.hpp"

#include <cctype>
#include <cstddef>
#include <iostream>
#include <list>
#include <sstream>
#include <string>

static bool	isValidToken(char token);
static bool	checkPolishNotation(std::list<char>	*operation);
static bool	isSign(char	token);

bool	error(int i, std::string token)
{
	std::cerr << "Error: " << g_error[i] << token << std::endl;
	return false;
}

bool	parseInput(std::list<char>	*operation, std::string line)
{
	std::stringstream	ss(line);
	std::string			tokStr;
	char				token;

	// Check if tokens are {0-9, +, -, *, /}
	while (ss >> tokStr)
	{
		if (tokStr.length() != 1)
			return (error(ERR_FORB_TOK, tokStr));
		token = tokStr[0];
		if (!isValidToken(token))
			return (error(ERR_FORB_TOK, tokStr));
		operation->push_back(token);
	}

	// Check if it has mathematical sense
	return (checkPolishNotation(operation));
}

long	solveOperation(std::list<char>	*operation)
{
	(void)operation;
	long	result = 0;
	return (result);
}

// ----------------------------- STATIC FUNCTIONS ------------------------------

static bool isValidToken(char token)
{
	return (isdigit(token) || isSign(token));
}

static bool	checkPolishNotation(std::list<char>	*operation)
{
	if (operation->empty())
		return (false);

	std::list<char>::iterator	it = operation->begin();
	if (!isdigit(*it))
		return (error(ERR_SYNT, ""));
	
	it++;
	size_t	digits = 0;
	size_t	signs = 0;
		
	while (it != operation->end())
	{
		while (it != operation->end() && isdigit(*it))
		{
			digits++;
			it++;
		}
		while (it != operation->end() && isSign(*it))
		{
			signs++;
			it++;
		}
		if (digits != signs)
			return (error(ERR_SYNT, ""));
		digits = 0;
		signs = 0;
	}
	return true;
}

static	bool isSign(char	token)
{
	return (token == '+' || token == '-' || token == '*' || token == '/');
}
