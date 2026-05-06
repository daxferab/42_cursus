#include "include/BitcoinExchange.hpp"

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <algorithm>

static bool	checkLineFormat(std::string line, s_data *dataPair);
static bool	checkDate(std::string date);
static bool	checkValue(float value);

bool	error(int i)
{
	std::cerr << "Error: " << g_error[i];
	if (i != ERR_INPUT)
		std::cerr << std::endl;
	return false;
}

void	insertPair(std::map<std::string, float>* database, std::string line)
{
	std::stringstream				ss(line);
	std::pair<std::string, float>	newPair;
	float							price;

	std::getline(ss, newPair.first, ',');
	ss >> price;
	newPair.second = price;
	database->insert(newPair);
}

bool	checkLine(std::string line, s_data* dataPair)
{
	std::string			pipe;

	if (!checkLineFormat(line, dataPair) || !checkDate(dataPair->date) || !checkValue(dataPair->value))
		return false;
	return true;
}

void	printMatch(std::map<std::string, float> database, s_data dataPair)
{
	float									result;
	std::map<std::string, float>::iterator	it = database.lower_bound(dataPair.date);

	if (it != database.end() && it->first == dataPair.date) // Match
	{
		result = it->second * dataPair.value;
		std::cout << dataPair.date << " => " << dataPair.value << " = " << result << std::endl;
	}
	else if (it != database.begin()) // Not match (use lower bound)
	{
		--it;
		result = it->second * dataPair.value;
		std::cout << dataPair.date << " => " << dataPair.value << " = " << result << std::endl;
	}
	else // Date lower than stored ones (it cant get the lower bound)
		error(ERR_DATE_LOW);
}

// ----------------------------- STATIC FUNCTIONS ------------------------------

static bool	checkLineFormat(std::string line, s_data *dataPair)
{
	size_t spaces = std::count(line.begin(), line.end(), ' ');
	if (spaces != 2)
	{
		error(ERR_INPUT);
		std::cerr << line << std::endl;
		return (false);
	}

	std::stringstream	ss(line);
	std::string			pipe;

	ss >> dataPair->date;
	ss >> pipe;
	ss >> dataPair->value;
	if (pipe != "|")
		return (error(ERR_INPUT));
	if (ss.fail())
		return (error(ERR_VALUE_FORMAT));
	return (true);
}

static bool	checkDate(std::string date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (error(ERR_DATE_FORMAT));
	for (int i = 0; i < 10; ++i)
		if (i != 4 && i != 7 && !std::isdigit(date[i])) 
			return error(ERR_DATE_FORMAT);

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 1 || month < 1 || month > 12)
		return (error(ERR_DATE_BOUNDS));
	if (day < 1 || day > 31)
		return (error(ERR_DATE_BOUNDS));

	int daysInMonth[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (day > daysInMonth[month])
		return (error(ERR_DATE_BOUNDS));
	return true;
}

static bool	checkValue(float value)
{
	if (value < 0)
		return (error(ERR_VALUE_NEGATIVE));
	if (value > 1000)
		return (error(ERR_VALUE_TOO_LARGE));
	return true;
}
