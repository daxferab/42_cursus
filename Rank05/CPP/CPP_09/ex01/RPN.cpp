#include "include/RPN.hpp"

#include <iostream>
#include <list>
#include <sstream>
#include <string>

static bool isValidToken(char token);

bool	error(int i, std::string token)
{
	std::cerr << "Error: " << g_error[i] << token << std::endl;
	return false;
}

bool	parseOperation(std::list<char>	*operation, std::string line)
{
	std::stringstream	ss(line);
	std::string			tokStr;
	char				token;

	while (ss >> tokStr)
	{
		if (tokStr.length() != 1)
			return (error(ERR_FORB_TOK, tokStr));
		token = tokStr[0];
		if (!isValidToken(token))
			return (error(ERR_FORB_TOK, tokStr));
		operation->push_back(token);
	}
	return true;
}

static bool isValidToken(char token)
{
	if ((token < 48 || token > 57) && token != '*' && token != '+' && token != '-' && token != '/')
		return false;
	return true;
}
