#ifndef BITCOINDATABASE_HPP
#define BITCOINDATABASE_HPP

#include <map>
#include <string>

class BitcoinDatabase {
	private:
		std::map<std::string, float>	_database;
	public:
		BitcoinDatabase();
		BitcoinDatabase(const BitcoinDatabase& other);
		BitcoinDatabase &operator=(const BitcoinDatabase& other);

		void	appendEntry(std::string key, float value);
		float	returnValue(std::string	key);
};

#endif
