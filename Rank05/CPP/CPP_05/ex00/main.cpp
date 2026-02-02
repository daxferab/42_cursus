#include "include/Bureaucrat.hpp"

int main(void)
{
	try
	{
		std::cout << "---------Creating valid object---------" << std::endl;
		Bureaucrat	Robert("Robert", 1);

		std::cout << Robert << std::endl;
		try
		{
			std::cout << "Substract 1: ";
			Robert.decrementGrade();
			std::cout << Robert << std::endl;
			std::cout << "Add 1: ";
			Robert.incrementGrade();
			std::cout << Robert << std::endl;
			std::cout << "Add 1: ";
			Robert.incrementGrade();
			std::cout << Robert << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout<< std::endl;
	
	try
	{
		std::cout << "---Creating invalid object (too high)--" << std::endl;
		Bureaucrat	Addison("Addison", 0);

		std::cout << Addison << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout<< std::endl;
	
	try
	{
		std::cout << "---Creating invalid object (too low)---" << std::endl;
		Bureaucrat	Addison("Addison", 200);

		std::cout << Addison << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout<< std::endl;
}
