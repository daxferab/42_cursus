#include "include/WrongCat.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

WrongCat::WrongCat() : 
	_type("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called"<< std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	std::cout << "WrongCat Assignment Operator Called" << std::endl;

	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

void	WrongCat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

std::string	WrongCat::getType() const
{
	return(_type);
}
