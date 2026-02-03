#include "include/AAnimal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"

int	main()
{
	std::cout << "-----------Correct------------" << std::endl;
	AAnimal	*dog = new Dog();
	AAnimal	*cat = new Cat();

	std::cout << "------------------------------" << std::endl;
	std::cout << "Dog type is " << dog->getType() << std::endl;
	dog->makeSound();
	std::cout << "Cat type is " << cat->getType() << std::endl;
	cat->makeSound();
	std::cout << std::endl;

	std::cout << "-----------Cleaning-----------" << std::endl;
	delete dog;
	delete cat;
}
