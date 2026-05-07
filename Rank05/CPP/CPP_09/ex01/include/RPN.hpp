#ifndef RPN_HPP
#define RPN_HPP

#include <string>

const	std::string g_error[] = 
{
	"usage <./RPN input>.",
	"forbidden token.",
	"syntax error."
};

typedef enum e_error
{
	ERR_ARG,
	ERR_FORB_TOK,
	ERR_SYNT_ERR
} t_error;

bool	error(int i);

#endif
