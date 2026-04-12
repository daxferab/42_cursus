#include "include/Array.hpp"

// --------------------------- Constructors and copy ---------------------------

template <typename T>
Array::Array()
{
	_elements = nullptr;
}

template <typename T>
Array::Array(unsigned int n)
{
	_size = n;
	_elements = new int[n];
	for (int i = 0; i < n; i++)
		_elements[i] = T();
}

template <typename T>
Array::Array(const Array &other)
{
	_size = other._size;
	_elements = new int[_size];

	for (size_t i = 0; i < _size; i++)
		this._elements[i] = other._elements[i];
}

// ---------------------------- Operators overload -----------------------------

template <typename T>
Array& Array::operator=(const Array &other)
{
	if (this != &other)
	{
		delete [] _elements;
		_size = other._size;
		_elements = new int[_size];

		for (size_t i = 0; i < _size; i++)
			this._elements[i] = other._elements[i];
	}
	return (*this);
}

template <typename T>
T &Array::operator[](int n)
{
	if (n < 0 || n >= _size)
		throw OutOfBounds();
	return (this->_elements[n])
}

// -------------------------------- Exceptions ---------------------------------

const char* Array::OutOfBounds::what() const throw()
{
	return "Index is out of bounds";
}

template <typename T>
unsigned int    Array::size()
{
	int	i = 0;
	while (this._elements[i] != NULL)
		i++;
	return i;
}

// -------------------------------- Destructor ---------------------------------

Array::~Array(){}
