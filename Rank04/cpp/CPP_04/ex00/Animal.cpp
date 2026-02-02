#include "include/Animal.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

Animal::Animal() : 
	_type("Default")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : 
	_type(other._type)
{
	std::cout << "Animal copy constructor called"<< std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
	if (this != &other) {
		_type = other._type;
	}
	std::cout << "Animal Assignment Operator Called" << std::endl;

	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

std::string Animal::getType() const
{
	return(_type);
}

void Animal::makeSound() const
{
	std::cout << "What do I say?" << std::endl;
}
