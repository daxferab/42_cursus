#include "include/LineParser.hpp"
#include <algorithm>
#include <exception>
#include <sstream>
#include <stdexcept>

// ------------------------------------------------------------ MEMBER FUNCTIONS

t_pair	LineParser::parseLine(std::string& line)
{
	try {
		t_pair pair = validLineFormat(line);
		checkDate(pair.date);
		checkValue(pair.value);
		return pair;
	} catch (std::exception &e) {
		throw;
	}
}

t_pair	LineParser::validLineFormat(std::string line)
{
	size_t	spaces = std::count(line.begin(), line.end(), ' ');
	if (spaces != 2)
		throw std::invalid_argument("wrong input");
	
	t_pair	pair;
	std::stringstream	ss(line);
	std::string			pipe;

	ss >> pair.date;
	ss >> pipe;
	ss >> pair.value;
	if (pipe != "|")
		throw std::invalid_argument("wrong input");
	if (ss.fail())
		throw std::out_of_range("value is not a float or int");
	return (pair);
}

// ----------------------------------------------------- STATIC HELPER FUNCTIONS

bool	LineParser::checkDate(std::string date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		throw std::out_of_range("date is not yyyy-mm-dd");
	for (int i = 0; i < 10; ++i)
		if (i != 4 && i != 7 && !std::isdigit(date[i])) 
			throw std::out_of_range("date is not yyyy-mm-dd");

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 1 || month < 1 || month > 12)
		throw std::out_of_range("date is impossible");
	if (day < 1 || day > 31)
		throw std::out_of_range("date is impossible");

	int daysInMonth[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (day > daysInMonth[month])
		throw std::out_of_range("date is impossible");
	return true;
}

bool	LineParser::checkValue(float value)
{
	if (value < 0)
		throw std::out_of_range("value is negative");
	if (value > 1000)
		throw std::out_of_range("value is too large (>1000)");
	return true;
}
