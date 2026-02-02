#include "include/AForm.hpp"
#include "include/Bureaucrat.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

AForm::AForm() : 
	_name("default"),
	_signed(false),
	_signGrade(1),
	_exeGrade(1)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int sign, int exe) : 
	_name(name),
	_signed(false),
	_signGrade(sign),
	_exeGrade(exe)
{
	if (sign > 150 || exe > 150)
		throw GradeTooLowException();
	if (sign < 1 || exe < 1)
		throw GradeTooHighException();
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm &other) : 
	_name(other._name),
	_signed(other._signed),
	_signGrade(other._signGrade),
	_exeGrade(other._exeGrade)
{
	std::cout << "AForm copy constructor called"<< std::endl;
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other) {
		_signed = other._signed;
	}
	std::cout << "AForm Assignment Operator Called" << std::endl;

	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

std::string	AForm::getName() const
{
	return _name;
}

bool	AForm::getSigned() const
{
	return _signed;
}

int	AForm::getSignGrade() const
{
	return _signGrade;
}

int	AForm::getExeGrade() const
{
	return _exeGrade;
}

void	AForm::beSigned(Bureaucrat *bureaucrat)
{
	if (bureaucrat->getGrade() > getSignGrade())
		throw GradeTooLowException();
	_signed = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!_signed)
		throw FormNotSigned();
	if (executor.getGrade() > getExeGrade())
		throw GradeTooLowException();
	executeAction();
	std::cout << executor.getName() << " executed " << getName() << std::endl;
}

std::ostream &operator<<(std::ostream& so, AForm& f)
{
	so << "Form named " << f.getName() << " is ";
	if (!f.getSigned()) so << "not ";
	so << "signed, you need grade " << f.getSignGrade() << " to sign it ";
	so << "and grade " << f.getExeGrade() << " to execute it.";
	return so;
}

/***************************** EXCEPTIONS *******************************/

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* AForm::FormNotSigned::what() const throw()
{
	return ("Form is not signed");
}
