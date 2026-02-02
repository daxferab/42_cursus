#include "include/RobotomyRequestForm.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

RobotomyRequestForm::RobotomyRequestForm() : 
	AForm("robotomy", 72, 45),
	_target("none")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
	AForm("robotomy", 72, 45),
	_target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : 
	AForm(other),
	_target(other._target)
{
	std::cout << "RobotomyRequestForm copy constructor called"<< std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	std::cout << "RobotomyRequestForm Assignment Operator Called" << std::endl;

	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

void	RobotomyRequestForm::executeAction() const
{
	std::cout << "Performing robotomy..." << std::endl;
	std::cout << "brrrrrrrrrrrr" << std::endl;
	bool success = rand() % 2;
	if (success)
		std::cout << _target << " has been robotomized!" << std::endl;
	else
		std::cout << "Robotomy to " << _target << " failed:(" << std::endl;
}
