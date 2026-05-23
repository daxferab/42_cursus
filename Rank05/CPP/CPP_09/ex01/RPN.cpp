#include "include/RPN.hpp"

#include <cctype>
#include <cstddef>
#include <exception>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cstdlib>

static const	std::string g_error[] = 
{
	"usage <./RPN input>",
	"forbidden token -> ",
	"syntax error",
	"cannot divide by zero"
};

static bool	isValidToken(std::string token);
static bool	isSign(char	token);
static bool	checkPolishNotation(std::list<std::string>	&operation);
static long solveSign(std::list<std::string>::iterator a, std::list<std::string>::iterator b, char s);

bool	error(int i, std::string token)
{
	std::cerr << RED << "Error: " << g_error[i] << token << std::endl;
	return false;
}

bool	parseInput(std::list<std::string> &operation, std::string line)
{
	std::stringstream	ss(line);
	std::string			token;

	// Check if tokens are {0-9, +, -, *, /}
	while (ss >> token)
	{
		if (!isValidToken(token))
			return (error(ERR_FORB_TOK, token));
		operation.push_back(token);
	}

	// Check if it has mathematical sense
	return (checkPolishNotation(operation));
}

std::string solveOperation(std::list<std::string>	&operation)
{
	long	result = 0;

	std::list<std::string>::iterator	it;
	std::list<std::string>::iterator	ita;
	std::list<std::string>::iterator	itb;

	while (operation.size() > 1)
	{
		it = operation.begin();
		while (isdigit((*it)[0]))
			it++;

		ita = it;
		itb = it;
		std::advance(ita, -2);
		std::advance(itb, -1);
		try
		{
			result = solveSign(ita, itb, (*it)[0]);
			std::stringstream ss;
			ss << result;
			operation.insert(it, ss.str());
			operation.erase(it);
			operation.erase(ita);
			operation.erase(itb);
		} catch (std::exception &e) {
			throw;
		}
	}
	return (*operation.begin());
}

// ----------------------------- STATIC FUNCTIONS ------------------------------

static bool isValidToken(std::string token)
{
	return (token.length() == 1 || isdigit(token[0]) || isSign(token[0]));
}

static	bool isSign(char	token)
{
	return (token == ADD || token == SUBSTRACT || token == MULTIPLY || token == DIVIDE);
}

static bool	checkPolishNotation(std::list<std::string>	&operation)
{
	if (operation.empty())
		return (false);

	std::list<std::string>::iterator	it = operation.begin();
	if (!isdigit((*it)[0]))
		return (error(ERR_SYNT, ""));
	
	it++;
	size_t	digits = 0;
	size_t	signs = 0;
		
	while (it != operation.end())
	{
		while (it != operation.end() && isdigit((*it)[0]))
		{
			digits++;
			it++;
		}
		while (it != operation.end() && isSign((*it)[0]))
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

static long solveSign(std::list<std::string>::iterator a, std::list<std::string>::iterator b, char s)
{
	long al = atol(a->c_str());
	long bl = atol(b->c_str());
	switch (s) {
		case ADD:
			return al + bl;
		case SUBSTRACT:
			return al - bl;
		case MULTIPLY:
			return al * bl;
		case DIVIDE:
			if (bl == 0)
				throw std::out_of_range("Cannot divide by zero");
			return al / bl;
	}
	return 0;
}
