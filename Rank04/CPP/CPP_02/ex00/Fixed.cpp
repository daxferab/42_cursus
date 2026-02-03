#include "include/Fixed.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

Fixed::Fixed() : 
	_value(0)
{
	std::cout << "Fixed default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : 
	_value(other.getRawBits())
{
	std::cout << "Fixed copy constructor called"<< std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Fixed Assignment Operator Called" << std::endl;
	if (this != &other) {
		_value = other.getRawBits();
	}

	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Fixed was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member funciton called" << std::endl;
	return(_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
	std::cout << "setRawBits member funciton called" << std::endl;
}
