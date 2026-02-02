#include "../inc/Ice.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

Ice::Ice() : 
	_type("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : 
	_type(other._type)
{
	std::cout << "Ice copy constructor called"<< std::endl;
}

Ice& Ice::operator=(const Ice &other)
{
	if (this != &other) {
		_type = other._type;
	}
	std::cout << "Ice Assignment Operator Called" << std::endl;

	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

AMateria*	Ice::clone()const
{
	AMateria	*clone = new Ice(*this);
	return (clone);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
