#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
private:
	std::string	_type;
	Brain		*_brain;
public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog();

	std::string		getType() const;
	void			makeSound() const;
	void			setIdea(int i, std::string idea);
	std::string		getIdea(int i);
};

#endif
