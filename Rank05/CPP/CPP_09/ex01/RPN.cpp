#include "include/RPN.hpp"

#include <cctype>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <string>

static bool	isValidToken(char token);
static bool	isSign(char	token);
static bool	checkPolishNotation(std::list<char>	*operation);
static long solveSign(long a, long b, char s);

bool	error(int i, std::string token)
{
	std::cerr << RED << "Error: " << g_error[i] << token << std::endl;
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
	long	result = 0;

	std::list<char>::iterator	it;
	std::list<char>::iterator	ita;
	std::list<char>::iterator	itb;

	while (operation->size() > 1)
	{
		it = operation->begin();
		while (isdigit(*it))
			it++;

		ita = it;
		itb = it;
		std::advance(ita, -2);
		std::advance(itb, -1);
		result = solveSign(*ita - '0', *itb - '0', *it);
		operation->insert(it, result + '0');
		operation->erase(it);
		operation->erase(ita);
		operation->erase(itb);
	}
	return (*operation->begin() - '0');
}

// ----------------------------- STATIC FUNCTIONS ------------------------------

static bool isValidToken(char token)
{
	return (isdigit(token) || isSign(token));
}

static	bool isSign(char	token)
{
	return (token == ADD || token == SUBSTRACT || token == MULTIPLY || token == DIVIDE);
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

static long solveSign(long a, long b, char s)
{
	switch (s) {
		case ADD:
			return a + b;
		case SUBSTRACT:
			return a - b;
		case MULTIPLY:
			return a * b;
		case DIVIDE:
			return a / b;
	}
	return 0;
}
