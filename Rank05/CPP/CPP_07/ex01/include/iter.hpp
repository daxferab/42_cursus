#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>
#include <iostream>

template <typename T>
void	iter(T *array, size_t const length, void (*f)(T &))
{
	for (size_t i = 0; i < length; i++)
	{
		f(array[i]);
	}
}

template <typename T>
void	increment(T &var)
{
	var++;
}

template <typename T>
void	printConst(const T &var)
{
	std::cout << var << std::endl;
}

#endif
