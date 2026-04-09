#include "include/iter.hpp"

template <typename T>
void	printArray(T *array, size_t const length);

int	main()
{
	int				intArray[] = {1, 2, 3, 4, 5};
	double			doubleArray[] = {0.5, 1.5, 2.5, 3.5, 4.5};
	char			stringArray[] = {'a', 'b', 'c', 'd', 'e'};
	const int		constIntArray[] = {10, 20, 30, 40, 50};
	size_t const	length = 5;

	std::cout << "Original int array:" << std::endl;
	printArray(intArray, length);
	iter(intArray, length, increment);
	std::cout << "Incremented int array:" << std::endl;
	printArray(intArray, length);

	std::cout << "------------------------" << std::endl;

	std::cout << "Original double array:" << std::endl;
	printArray(doubleArray, length);
	iter(doubleArray, length, increment);
	std::cout << "Incremented double array:" << std::endl;
	printArray(doubleArray, length);

	std::cout << "------------------------" << std::endl;

	std::cout << "Original char array:" << std::endl;
	printArray(stringArray, length);
	iter(stringArray, length, increment);
	std::cout << "Incremented char array:" << std::endl;
	printArray(stringArray, length);

	std::cout << "------------------------" << std::endl;

	std::cout << "Const int array:" << std::endl;
	iter(constIntArray, length, printConst);
}

template <typename T>
void	printArray(T *array, size_t const length)
{
	std::cout << "Array = {" ;
	for (size_t i = 0 ; i < length; i++)
	{
		std::cout << array[i];
		if (i < length - 1) {std::cout << ", ";};
	}
	std::cout << "}" << std::endl;
}
