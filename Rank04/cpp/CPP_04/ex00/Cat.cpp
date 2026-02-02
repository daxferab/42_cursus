#include "include/Cat.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

Cat::Cat() : 
	_type("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called"<< std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout << "Cat Assignment Operator Called" << std::endl;

	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

std::string	Cat::getType() const
{
	return(_type);
}
