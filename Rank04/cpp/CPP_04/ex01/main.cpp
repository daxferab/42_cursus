#include "include/Animal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"

int	main()
{
	std::cout << "-----------Init Zoo-----------" << std::endl;
	Animal	*zoo[4];

	for (int i = 0; i < 4; i++)
	{
		i % 2 ? zoo[i] = new Dog(): zoo[i] = new Cat();
		std::cout << "Zoo " << i << " animal is " << zoo[i]->getType() << std::endl;
		zoo[i]->makeSound();
	}
	std::cout << std::endl;
	std::cout << "-------Deep copy check--------" << std::endl;

	Dog		*dog = new Dog();
	dog->setIdea(0, "food");
	Dog *dogCopy = dog;
	std::cout << "I'm a " << dog->getType() << " and I'm thinking about " << dog->getIdea(0) << std::endl;
	std::cout << "<copy> I'm a " << dogCopy->getType() << " and I'm thinking about " << dogCopy->getIdea(0) << std::endl;

	std::cout << std::endl;

	std::cout << "-----------Cleaning-----------" << std::endl;
	for (int i = 0; i < 4; i++)
		delete zoo[i];
	delete dog;
}
