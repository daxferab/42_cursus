#include "include/BitcoinExchange.hpp"

#include <fstream>
#include <map>
#include <string>
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
		return (error(ERR_ARG));

	// Open input file and db file
	std::ifstream					dbFile("data.csv");
	std::ifstream					inputFile(av[1]);
	if (dbFile.fail() || inputFile.fail())
	{
		dbFile.close();
		inputFile.close();
		return (error(ERR_OPEN_FILE));
	}

	// Save database in map
	std::map<std::string, float>	database;
	std::string 					line;
	while (std::getline(dbFile, line))
	{
		insertPair(&database, line);
	}

	//Read each line (skipping the first one)
	s_data	dataPair;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		if (!line.empty() && checkLine(line, &dataPair))
			printMatch(database, dataPair);
	}

	inputFile.close();
	dbFile.close();
	return 0;
}
