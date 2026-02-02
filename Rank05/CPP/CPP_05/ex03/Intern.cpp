#include "include/Intern.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "Intern copy constructor called"<< std::endl;
}

Intern& Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << "Intern Assignment Operator Called" << std::endl;

	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

AForm	*Intern::makeForm(std::string form, std::string target)
{
	std::string	names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	for (int i = 0; i < 3; i++)
	{
		if (form == names[i])
		{
			std::cout << "Intern creates form '" << form << "'" << std::endl;
			switch(i)
			{
                case 0:
                    return new ShrubberyCreationForm(target);
                case 1:
                    return new RobotomyRequestForm(target);
                case 2:
                    return new PresidentialPardonForm(target);
			}
		}
	}

	std::cout << "The name '" << form << "' doesn't match with any form" << std::endl;
	return (NULL);
}
