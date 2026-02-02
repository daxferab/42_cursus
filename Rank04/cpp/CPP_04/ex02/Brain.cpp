#include "include/Brain.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = "";
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other) : 
	_ideas(other._ideas)
{
	std::cout << "Brain copy constructor called"<< std::endl;
}

Brain& Brain::operator=(const Brain &other)
{
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain Assignment Operator Called" << std::endl;

	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

void	Brain::setIdea(int i, std::string idea)
{
	_ideas[i] = idea;
}

std::string	Brain::getIdea(int i) const
{
	return(_ideas[i]);
}
