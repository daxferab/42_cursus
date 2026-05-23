#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <string>

#define RED "\033[31m"
#define ADD '+'
#define SUBSTRACT '-'
#define MULTIPLY '*'
#define DIVIDE '/'

typedef enum e_error
{
	ERR_ARG,
	ERR_FORB_TOK,
	ERR_SYNT,
	ERR_ZERO_DIV
} t_error;

bool		error(int i, std::string token);

bool		parseInput(std::list<std::string> &operation, std::string line);
std::string	solveOperation(std::list<std::string> &operation);

#endif
