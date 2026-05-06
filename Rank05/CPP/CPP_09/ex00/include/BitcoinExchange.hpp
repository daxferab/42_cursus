#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

const	std::string g_error[] = 
{
	"usage <./btc input>.",
	"couldn't open file.",
	"wrong file format.",
	"wrong input => ",
	"value is negative.",
	"value is too large (>1000).",
	"value is not a float or int.",
	"date is not yyyy-mm-dd.",
	"date is impossible.",
	"date is lower than the stored dates."
};

typedef enum e_error
{
	ERR_ARG,
	ERR_OPEN_FILE,
	ERR_FILE_FORMAT,
	ERR_INPUT,
	ERR_VALUE_NEGATIVE,
	ERR_VALUE_TOO_LARGE,
	ERR_VALUE_FORMAT,
	ERR_DATE_FORMAT,
	ERR_DATE_BOUNDS,
	ERR_DATE_LOW
} t_error;

typedef struct s_data
{
	std::string	date;
	float		value;
} s_data;

bool	error(int i);

void	insertPair(std::map<std::string, float>* database, std::string line);
void	printMatch(std::map<std::string, float> database, s_data dataPair);
bool	checkLine(std::string line, s_data* dataPair);
bool	checkLineFormat(std::string line, s_data *dataPair);
bool	checkDate(std::string date);
bool	checkValue(float value);

#endif
