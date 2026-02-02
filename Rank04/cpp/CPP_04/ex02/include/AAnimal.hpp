#ifndef AAnimal_HPP
#define AAnimal_HPP
#include <iostream>

class AAnimal
{
protected:
	std::string	_type;
public:
	AAnimal();
	AAnimal(const AAnimal &other);
	AAnimal &operator=(const AAnimal &other);
	virtual ~AAnimal();

	virtual std::string		getType() const = 0;
	virtual void			makeSound() const = 0;
};

#endif