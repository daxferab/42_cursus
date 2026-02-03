#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria
{
	private:
		std::string	_type;

	public:
		Ice();
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
		~Ice();

		AMateria*	clone()const;
		void 		use(ICharacter& target);
};

#endif
