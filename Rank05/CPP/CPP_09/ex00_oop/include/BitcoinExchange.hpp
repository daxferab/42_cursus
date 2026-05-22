#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <string>
#define RED "\033[31m"

typedef enum e_error
{
	ERR_ARG,
	ERR_OPEN_FILE,
	ERR_INPUT,
	ERR_WRONG_HEADER
} t_error;

typedef struct s_pair {
	std::string	date;
	float		value;
} t_pair;

bool	error(int i);
void	printCoversion(float value, float amount, std::string date);

#endif
