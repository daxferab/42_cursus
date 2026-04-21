#include "include/Span.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <iterator>
#include <limits.h>
#include <stdint.h>
#include <vector>

/************************* ORTHODOX CANONICAL FORM ****************************/

Span::Span() : _N(0) {}

Span::Span(unsigned int n) : _N(n) {}

Span::Span(const Span &other) : _N(other._N), _list(other._list) {}

Span& Span::operator=(const Span &other)
{
	if (this != &other) {
		_N = other._N;
		_list = other._list;
	}
	return (*this);
}

Span::~Span() {}

/***************************** MEMBER FUNCTIONS *******************************/

void	Span::addNumber(int n)
{
	if (_list.size() >= _N )
		throw listFull();
	_list.push_back(n);
}

int		Span::shortestSpan()
{
	if (_list.size() < 2)
		throw listNotLongEnough();
	std::sort(_list.begin(),_list.end());
	int	span = _list.end() - _list.begin();
	for (size_t i = 0; i <=_list.size() - 2; i++)
	{
		if (_list[i + 1] - _list[i] < span)
			span = _list[i + 1] - _list[i];
	}
	return (span);
}

int		Span::longestSpan()
{
	if (_list.size() < 2)
		throw listNotLongEnough();
	return (
		*std::max_element(_list.begin(), _list.end()) -
		*std::min_element(_list.begin(), _list.end())
	);
}

void	Span::addMultiple(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_N - static_cast<int>(_list.size()) < std::distance(begin, end))
		throw listFull();
	std::copy(begin, end, std::back_inserter(_list));
}

