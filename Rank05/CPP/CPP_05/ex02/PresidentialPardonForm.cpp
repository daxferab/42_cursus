#include "include/PresidentialPardonForm.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

PresidentialPardonForm::PresidentialPardonForm() : 
	AForm("pardon", 25, 5),
	_target("none")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
	AForm("pardon", 25, 5),
	_target(target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : 
	AForm(other),
	_target(other._target)
{
	std::cout << "PresidentialPardonForm copy constructor called"<< std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	std::cout << "PresidentialPardonForm Assignment Operator Called" << std::endl;

	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

void		PresidentialPardonForm::executeAction() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
