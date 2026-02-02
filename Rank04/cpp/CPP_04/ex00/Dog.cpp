#include "include/Dog.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

Dog::Dog() : 
	_type("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called"<< std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout << "Dog Assignment Operator Called" << std::endl;

	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

std::string	Dog::getType() const
{
	return(_type);
}
