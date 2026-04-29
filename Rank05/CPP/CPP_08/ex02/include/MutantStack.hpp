#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
public:
	//-------------------------------------- Constructors and copy
	MutantStack();
	MutantStack(const MutantStack &other);

	//-------------------------------------- Operators overload
	MutantStack	&operator=(const MutantStack &other);
	
	//-------------------------------------- Member functions
    typedef typename std::stack<T, std::deque<T> >::container_type::const_iterator iterator;
	typename MutantStack<T>::iterator	begin();
	typename MutantStack<T>::iterator	end();

	//-------------------------------------- Destructor
	~MutantStack();
};

# include "../MutantStack.tpp"

#endif
