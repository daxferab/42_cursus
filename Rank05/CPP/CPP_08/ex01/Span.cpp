#include "include/Span.hpp"
#include <algorithm>
#include <cstddef>
#include <limits.h>
#include <stdint.h>
#include <vector>

/************************* ORTHODOX CANONICAL FORM ****************************/

Span::Span() : _N(0), _size(0) {}

Span::Span(unsigned int n) : _N(n), _size(0)
{

}

Span::Span(const Span &other) : _N(other._N), _size(other._size){}

Span& Span::operator=(const Span &other)
{
	if (this != &other) {
		_N = other._N;
		_size = other._size;
		// TODO: copy list
	}
	return (*this);
}

Span::~Span() {}

/***************************** MEMBER FUNCTIONS *******************************/

void	Span::addNumber(int n)
{
	if (_size >= _N )
		throw listFull();
	_list.push_back(n);
	_size++;
}

int		Span::shortestSpan()
{
	if (_size < 2)
		throw listNotLongEnough();
	int	span = INT_MAX;
	std::sort(_list.begin(),_list.end());
	for (size_t i = 0; i <=_list.size() - 2; i++)
	{
		if (_list[i + 1] - _list[i] < span)
			span = _list[i + 1] - _list[i];
	}
	return (span);
}

int		Span::longestSpan()
{
	if (_size < 2)
		throw listNotLongEnough();
	return (
		*std::max_element(_list.begin(), _list.end()) -
		*std::min_element(_list.begin(), _list.end())
	);
}

// void	Span::addMultiple()
// {

// }
