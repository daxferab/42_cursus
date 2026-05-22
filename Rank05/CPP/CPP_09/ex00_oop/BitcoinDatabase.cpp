#include "include/BitcoinDatabase.hpp"
#include <stdexcept>

// ---------------------------------------------------------------- CONSTRUCTORS
BitcoinDatabase::BitcoinDatabase() {}

BitcoinDatabase::BitcoinDatabase(const BitcoinDatabase& other) : _database(other._database) {}

BitcoinDatabase &BitcoinDatabase::operator=(const BitcoinDatabase& other) {
	if (this != &other)
		_database = other._database;
	return (*this);
}

// ------------------------------------------------------------ MEMBER FUNCTIONS

void	BitcoinDatabase::appendEntry(std::string key, float value)
{
	std::pair<std::string, float>	newPair;

	newPair.first = key;
	newPair.second = value;
	_database.insert(newPair);
}

float	BitcoinDatabase::returnValue(std::string key)
{
	std::map<std::string, float>::iterator	it = _database.lower_bound(key);

	if (it != _database.end())
	{
		if (it->first == key) // Match
			return it->second;
		if (it != _database.begin()) // Not match (use lower bound)
		{
			--it;
			return it->second;
		}
	}
	throw std::out_of_range("Date is lower than the stored dates.");
}

