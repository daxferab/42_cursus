#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <string>

#define RED "\033[31m"

const	std::string g_error[] = 
{
	"usage <./RPN input>",
	"forbidden token -> ",
	"syntax error"
};

typedef enum e_error
{
	ERR_ARG,
	ERR_FORB_TOK,
	ERR_SYNT
} t_error;

bool	error(int i, std::string token);

bool	parseInput(std::list<char>	*operation, std::string line);
long	solveOperation(std::list<char>	*operation);

#endif
