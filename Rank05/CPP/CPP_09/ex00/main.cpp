#include "include/BitcoinExchange.hpp"
#include "include/BitcoinDatabase.hpp"
#include "include/LineParser.hpp"

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

int main(int ac, char **av)
{
	if (ac != 2)
		return (error(ERR_ARG));

	// --------------------------------------------- Open input file and db file
	std::ifstream					dbFile("data.csv");
	std::ifstream					inputFile(av[1]);
	if (dbFile.fail() || inputFile.fail())
	{
		dbFile.close();
		inputFile.close();
		return (error(ERR_OPEN_FILE));
	}

	// ---------------------------------------------------- Save database in map
	BitcoinDatabase	database;
	std::string		line;
	t_pair			linePair;
	
	std::getline(dbFile, line); // Skip first line
	while (std::getline(dbFile, line))
	{
		if (line.empty()) continue;

		std::stringstream	stream(line);
		std::getline(stream, linePair.date, ',');
		stream >> linePair.value;
		database.appendEntry(linePair.date, linePair.value);
	}

	// --------------------------------------------------- Parse and match imput
	float	value;

	std::getline(inputFile, line); // Check first line
	if (line != "date | value") return (error(ERR_WRONG_HEADER));
	while (std::getline(inputFile, line))
	{
		try {
			linePair = LineParser::parseLine(line);
			value = database.returnValue(linePair.date);
			printCoversion(value, linePair.value, linePair.date);
		} catch (const std::invalid_argument& e) {
			std::cerr << RED << "Error: " << e.what() << " => " << line << std::endl;
		} catch (const std::exception& e) {
			std::cerr << RED << "Error: " << e.what() << std::endl;
		}
	}

	inputFile.close();
	dbFile.close();
	return 0;
}
