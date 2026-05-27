#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <list>

#define RED "\033[31m"

const	std::string g_error[] =
{
	"usage <./PmergeMe input>",
};

typedef enum e_error
{
	ERR_ARG,
} t_error;

bool	error(int i);
bool	printFormat(int size, char **args, std::vector<int> vect, double vtime, double ltime);

double	vectorMergeInsert(int size, char **seq, std::vector<int>& vect);
double	listMergeInsert(int size, char **seq, std::list<int>& list);

#endif
