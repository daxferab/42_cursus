#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>

#define RED "\033[31m"

const	std::string g_error[] =
{
	"usage <./PmergeMe input>",
	"argument must be a positive integer sequence",
	"there can't be duplicate numbers",
};

typedef enum e_error
{
	ERR_ARG,
	ERR_SEQUENCE,
	ERR_DUP
} t_error;

bool	error(int i);
bool	printInts(int size, char **args);

bool	vectorContainer(int size, char **list);

#endif
