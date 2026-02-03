#include "include/Fixed.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

Fixed::Fixed() : 
	_value(0)
{
	std::cout << "Fixed default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	setRawBits(value << _fractionalBits);
	std::cout << "Fixed int constructor called. Value = " << _value << "." << std::endl;
}

Fixed::Fixed(const float value)
{
	setRawBits(roundf(value * 256));
	std::cout << "Fixed float constructor called. Value = " << _value << "." << std::endl;
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

/***************************** OPERATOR OVERLOAD ******************************/

/* COMPARISION */

bool	Fixed::operator>(const Fixed &other) const
{
	return (getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (getRawBits() != other.getRawBits());
}

/* ARITHMETIC */

Fixed	Fixed::operator+(const Fixed &other) const
{
	return (Fixed(toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return (Fixed(toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return (Fixed(toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	if (other.toFloat() != 0.0)
		return (Fixed(toFloat() / other.toFloat()));
	return(Fixed(0));
}

/* PRE/POST - DECREMENT/INCREMENT */

Fixed	&Fixed::operator++()
{
	setRawBits(getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator--()
{
	setRawBits(getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	++(*this);
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	--(*this);
	return (tmp);
}

/***************************** MEMBER FUNCTIONS *******************************/

int		Fixed::getRawBits() const
{
	return(_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float	Fixed::toFloat() const
{
	return (static_cast<float>(getRawBits()) / (1 << _fractionalBits));
}

int		Fixed::toInt() const
{
	return (getRawBits() >> _fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
    os << f.toFloat();
    return os;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

