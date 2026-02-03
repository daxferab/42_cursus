#include "../inc/Cure.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

Cure::Cure() : 
	_type("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &other) : 
	_type(other._type)
{
	std::cout << "Cure copy constructor called"<< std::endl;
}

Cure& Cure::operator=(const Cure &other) //FIXME: dont copy type?
{
	if (this != &other) {
		_type = other._type;
	}
	std::cout << "Cure Assignment Operator Called" << std::endl;

	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

AMateria*	Cure::clone()const
{
	AMateria	*clone = new Cure(*this);
	return (clone);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
