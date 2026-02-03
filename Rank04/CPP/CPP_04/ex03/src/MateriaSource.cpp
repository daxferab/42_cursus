#include "../inc/MateriaSource.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

MateriaSource::MateriaSource()
{
	for (int i = 0; i < INV_SIZE; i++)
		_materias[i] = '\0';
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource()
{
	for (int i = 0; i < INV_SIZE; i++)
		_materias[i] = '\0';
	std::cout << "MateriaSource created." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	//TODO: fill inventory
	std::cout << "MateriaSource copy constructor called"<< std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other) {
		//_atrib = other._atrib;
	}
	std::cout << "MateriaSource Assignment Operator Called" << std::endl;

	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < INV_SIZE; i++)
	{
		if (!_materias[i])
		{
			_materias[i] = m;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < INV_SIZE; i++)
		if (_materias[i]->getType() == type)
			return (_materias[i]);
	return (0);
}
