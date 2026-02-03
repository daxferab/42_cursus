#include "include/Animal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"

int	main()
{
	std::cout << "-----------Correct------------" << std::endl;
	Animal	*dog = new Dog();
	Animal	*cat = new Cat();
	Animal	*animal = new Animal();

	std::cout << "------------------------------" << std::endl;
	std::cout << "Dog type is " << dog->getType() << std::endl;
	dog->makeSound();
	std::cout << "Cat type is " << cat->getType() << std::endl;
	cat->makeSound();
	std::cout << "Animal type is " << animal->getType() << std::endl;
	animal->makeSound();
	std::cout << std::endl;

	std::cout << "----------Incorrect-----------" << std::endl;
	WrongAnimal	*wrongCat = new WrongCat();
	WrongAnimal	*wrongAnimal = new WrongAnimal();

	std::cout << "------------------------------" << std::endl;
	std::cout << "WrongCat type is " << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	std::cout << "WrongAnimal type is " << wrongAnimal->getType() << std::endl;
	wrongAnimal->makeSound();
	std::cout << std::endl;

	std::cout << "-----------Cleaning-----------" << std::endl;
	delete animal;
	delete dog;
	delete cat;
	delete wrongAnimal;
	delete wrongCat;
}
