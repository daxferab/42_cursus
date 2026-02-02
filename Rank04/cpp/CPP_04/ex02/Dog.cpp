#include "include/Dog.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

Dog::Dog() : 
	_type("Dog")
{
	_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
	std::cout << "Dog copy constructor called"<< std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
	if (this != &other) {
		AAnimal::operator=(other);
	}
	std::cout << "Dog Assignment Operator Called" << std::endl;

	return (*this);
}

Dog::~Dog()
{
	delete _brain;
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

void	Dog::setIdea(int i, std::string idea)
{
	if (i < 0 || i > 99)
	{
		std::cout << "Not enough brain for ideas!" << std::endl;
		return;
	}
	_brain->setIdea(i, idea);
}

std::string	Dog::getIdea(int i)
{
	if (i < 0 || i > 99)
		return ("I don`t have any idea stored there");
	return(_brain->getIdea(i));
}
