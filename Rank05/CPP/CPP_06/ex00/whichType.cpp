#include "include/whichType.hpp"

static bool	isChar(std::string str);
static bool	isInt(std::string str);
static bool	isFloat(std::string str);
static bool	isDouble(std::string str);
static bool	isSpecial(std::string str);
static bool hasDecimalPoint(std::string num);

std::string	strType(std::string str)
{
	if (str.empty()) return NONE;
	if (isSpecial(str)) return SPECIAL;
	if (isChar(str)) return CHAR;
	if (isInt(str)) return INT;
	if (isDouble(str)) return DOUBLE;
	if (isFloat(str)) return FLOAT;
	return NONE;
}

static bool	isChar(std::string str)
{
	return (str.size() == 3 && str[0] == '\'' && str[2] == '\'');
}

static bool	isInt(std::string str)
{
	char	*end;
	long	num;

	num = strtol(str.c_str(), &end, 10);
	return (*end == '\0' && num >= INT_MIN && num <=INT_MAX);
}

static bool	isFloat(std::string str)
{
	char	*end;
	
	if (str.length() == 1 || !hasDecimalPoint(str)) return (false);
	strtof(str.c_str(), &end);
	return ((*end == 'f' || *end == 'F') && *(++end) == '\0');
}

static bool	isDouble(std::string str)
{
	char	*end;
	
	strtod(str.c_str(), &end);
	return (*end == '\0');
}

static bool	isSpecial(std::string str)
{
	return (str == "nan" || str == "nanf" || str == "-inf" || str == "-inff" || str == "+inf" || str == "+inff" || str == "inf" || str == "inff");
}

static bool hasDecimalPoint(std::string num)
{
	for (size_t i = 0; i < num.length(); i++)
		if (num.at(i) == '.')
			return true;
	return false;
}