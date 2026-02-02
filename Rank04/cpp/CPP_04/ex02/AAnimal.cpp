#include "include/AAnimal.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

AAnimal::AAnimal() : 
	_type("Default")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : 
	_type(other._type)
{
	std::cout << "AAnimal copy constructor called"<< std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &other)
{
	if (this != &other) {
		_type = other._type;
	}
	std::cout << "AAnimal Assignment Operator Called" << std::endl;

	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/
