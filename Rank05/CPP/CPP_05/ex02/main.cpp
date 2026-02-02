#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"

int main(void)
{
	ShrubberyCreationForm	shrub("Sahara");
	RobotomyRequestForm		robo("Rudolf");
	PresidentialPardonForm	presi("Frank");
	Bureaucrat				god("God", 1);
	Bureaucrat				human("Human", 150);
	srand(time(NULL));

	std::cout << std::endl;
	std::cout << "Created:" << std::endl;
	std::cout << god << std::endl;
	std::cout << std::endl;
	std::cout << "Trying to execute unsigned form..." << std::endl;

	try
	{
		shrub.execute(god);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Couldn't execute because " << e.what() << '\n';
	}
	god.executeForm(robo);
	human.executeForm(robo);
	std::cout << std::endl;
	std::cout << "Signing..." << std::endl;
	god.signForm(shrub);
	god.signForm(robo);
	god.signForm(presi);
	std::cout << std::endl;
	std::cout << "Executing forms..." << std::endl;
	god.executeForm(robo);
	human.executeForm(robo);
	try
	{
		shrub.execute(god);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Couldn't execute because " << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		robo.execute(god);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Couldn't execute because " << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		presi.execute(god);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Couldn't execute because " << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "Trying to execute without permissions..." << std::endl;
	try
	{
		presi.execute(human);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Couldn't execute because " << e.what() << '\n';
	}
	std::cout << std::endl;
}
