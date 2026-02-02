#include "../inc/AMateria.hpp" //FIXME: rm ../inc/

/************************* ORTHODOX CANONICAL FORM ****************************/

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) :
	_type(type)
{
	std::cout << "AMateria parametrized constructor called"<< std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	std::cout << "AMateria copy constructor called"<< std::endl;
}

AMateria& AMateria::operator=(const AMateria &other)
{
	if (this != &other) {
		//_atrib = other._atrib;
	}
	std::cout << "AMateria Assignment Operator Called" << std::endl;

	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

std::string const& AMateria::getType() const
{
	return(_type);
}

void AMateria::use(ICharacter& target)
{
	;
}

