#ifndef ITER_HPP
#define ITER_HPP
#include <stddef.h>
#include <iostream>

template <typename T, typename Func>
void	iter(T* array, const size_t lenght, Func func)
{
	for (size_t i = 0; i < lenght; i++)
	{
		func(array[i]);
	}
}

template <typename T, typename Func>
void	iter(const T* array, const size_t lenght, Func func)
{
	for (size_t i = 0; i < lenght; i++)
	{
		func(array[i]);
	}
}

template <typename T>
void	increment(T& element)
{
	element++;
}

template <typename T>
void	print(const T& value)
{
	std::cout << value << " ";
}

#endif
