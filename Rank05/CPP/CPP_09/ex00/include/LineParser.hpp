#ifndef LINEPARSER_HPP
#define LINEPARSER_HPP

#include <string>
#include "BitcoinExchange.hpp"

class LineParser {
	public:
		static t_pair	parseLine(std::string& line);

	private:
		LineParser();
		LineParser(const LineParser& other);
		LineParser &operator=(const LineParser& other);
		~LineParser();

		static t_pair	validLineFormat(std::string line);
		static bool		checkDate(std::string date);
		static bool		checkValue(float value);
};

#endif
