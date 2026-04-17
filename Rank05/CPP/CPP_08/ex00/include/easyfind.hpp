#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <exception>

class   noResult : public std::exception
{
	virtual const char* what() const throw() {
		return "Character not found in container";
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator pos;
	pos = std::find(container.begin(), container.end(), n);
	if (pos == container.end())
		throw noResult();
	return (pos);
}

#endif
