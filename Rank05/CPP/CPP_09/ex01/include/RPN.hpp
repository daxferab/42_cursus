#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <string>

const	std::string g_error[] = 
{
	"usage <./RPN input>.",
	"forbidden token -> ",
	"syntax error"
};

typedef enum e_error
{
	ERR_ARG,
	ERR_FORB_TOK,
	ERR_SYNT_ERR
} t_error;

bool	error(int i, std::string token);

bool	parseOperation(std::list<char>	*operation, std::string line);

#endif
