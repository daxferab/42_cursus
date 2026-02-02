#include "include/Form.hpp"
#include "include/Bureaucrat.hpp"

/************************* ORTHODOX CANONICAL FORM ****************************/

Form::Form() : 
	_name("default"),
	_signed(false),
	_signGrade(1),
	_exeGrade(1)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int sign, int exe) : 
	_name(name),
	_signed(false),
	_signGrade(sign),
	_exeGrade(exe)
{
	if (sign > 150 || exe > 150)
		throw GradeTooLowException();
	if (sign < 1 || exe < 1)
		throw GradeTooHighException();
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &other) : 
	_name(other._name),
	_signed(other._signed),
	_signGrade(other._signGrade),
	_exeGrade(other._exeGrade)
{
	std::cout << "Form copy constructor called"<< std::endl;
}

Form& Form::operator=(const Form &other)
{
	if (this != &other) {
		_signed = other._signed;
	}
	std::cout << "Form Assignment Operator Called" << std::endl;

	return (*this);
}

Form::~Form()
{
	std::cout << "Form was destroyed." << std::endl;
}

/***************************** MEMBER FUNCTIONS *******************************/

std::string	Form::getName() const
{
	return _name;
}

bool	Form::getSigned() const
{
	return _signed;
}

int	Form::getSignGrade() const
{
	return _signGrade;
}

int	Form::getExeGrade() const
{
	return _exeGrade;
}

void	Form::beSigned(Bureaucrat *bureaucrat)
{
	if (bureaucrat->getGrade() > getSignGrade())
		throw GradeTooLowException();
	_signed = true;
}

std::ostream &operator<<(std::ostream& so, Form& f)
{
	so << "Form named " << f.getName() << " is ";
	if (!f.getSigned()) so << "not ";
	so << "signed, you need grade " << f.getSignGrade() << " to sign it ";
	so << "and grade " << f.getExeGrade() << " to execute it.";
	return so;
}

/***************************** EXCEPTIONS *******************************/

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}
