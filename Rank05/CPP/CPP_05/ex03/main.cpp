#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/Intern.hpp"

int main(void)
{
	Intern	dummy;

	std::cout << std::endl;
	std::cout << "-----------Creating wrong name form-----------" << std::endl;
	std::cout << std::endl;
	AForm	*wrong = dummy.makeForm("wrong name", "random");
	(void)wrong;
	std::cout << std::endl;
	std::cout << "-----------Creating shrubbery form-----------" << std::endl;
	std::cout << std::endl;
	AForm	*shrub = dummy.makeForm("shrubbery creation", "random");
	std::cout << "--Created form: " << shrub->getName() << std::endl;
	std::cout << std::endl;
	std::cout << "-----------Creating robotomy form-----------" << std::endl;
	std::cout << std::endl;
	AForm	*robo = dummy.makeForm("robotomy request", "random");
	std::cout << "--Created form: " << robo->getName() << std::endl;
	std::cout << std::endl;
	std::cout << "-----------Creating presidential form-----------" << std::endl;
	std::cout << std::endl;
	AForm	*presi = dummy.makeForm("presidential pardon", "random");
	std::cout << "--Created form: " << presi->getName() << std::endl;
	std::cout << std::endl;

	delete wrong;
	delete shrub;
	delete robo;
	delete presi;
}
