#include "include/WrongAnimal.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

WrongAnimal::WrongAnimal() : 
	_type("Default")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : 
	_type(other._type)
{
	std::cout << "WrongAnimal copy constructor called"<< std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other) {
		_type = other._type;
	}
	std::cout << "WrongAnimal Assignment Operator Called" << std::endl;

	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

std::string WrongAnimal::getType() const
{
	return(_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "What do I say?" << std::endl;
}
