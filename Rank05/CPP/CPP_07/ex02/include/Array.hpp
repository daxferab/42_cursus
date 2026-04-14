#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <cstdio>

template <typename T>
class Array
{
private:
	T*		_elements;
	size_t	_size;

public:
	//-------------------------------------- Constructors and copy
	Array();
	Array(unsigned int n);
	Array(const Array &other);

	//-------------------------------------- Operators overload
	Array	&operator=(const Array &other);
	T		&operator[](size_t n);
	
	//-------------------------------------- Member functions
	unsigned int	size() const;

	//-------------------------------------- Exceptions
	class OutOfBounds : public std::exception
	{
		virtual const char* what() const throw();
	};

	//-------------------------------------- Destructor
	~Array();
};

# include "../Array.tpp"

#endif
