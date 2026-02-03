#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource
{
	private:
		AMateria*	_materias[4];
	public:
		MateriaSource();
		MateriaSource(); //Params
		MateriaSource(const MateriaSource &other);
		MateriaSource &operator=(const MateriaSource &other);
		~MateriaSource();

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
};

#endif
