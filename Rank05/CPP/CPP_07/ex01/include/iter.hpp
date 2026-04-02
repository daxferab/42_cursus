#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void	iter(T *array[], size_t const length, void (*f)(T))
{
	for (int i = 0; i < length; i++)
	{
		f(array[i]);
	}
}

template <typename T>
void	increment(T	var)
{
	var++;
}

#endif
